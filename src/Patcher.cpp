#include "Patcher.h"
#include "bsdiff.h"
#include "bspatch.h"
#include <unistd.h>
#include <iostream>
#include <cstdint>
using namespace std;
TV_NAME_SPACE_BEGIN
Patcher Patcher::smInstance;
#define err(...) fprintf(__VA_ARGS__)
Patcher::Patcher()
{
    std::cout<<"hello world"<<std::endl;
}
void Patcher::DoPatch(std::string oldFile,std::string newFile,std::string patchFile)
{
	FILE * f;
	int fd;
	int bz2err;
	uint8_t header[24];
	uint8_t *old, *_new;
	int64_t oldsize, newsize;
	BZFILE* bz2;
	struct bspatch_stream stream;
	struct stat sb;

	/* Open patch file */
	if ((f = fopen(patchFile.c_str(), "r")) == NULL)
		err(1, "fopen(%s)", patchFile.c_str());

	/* Read header */
	if (fread(header, 1, 24, f) != 24) {
		if (feof(f))
			errx(1, "Corrupt patch\n");
		err(1, "fread(%s)", patchFile.c_str());
	}

	/* Check for appropriate magic */
	if (memcmp(header, "ENDSLEY/BSDIFF43", 16) != 0)
		errx(1, "Corrupt patch\n");

	/* Read lengths from header */
	newsize=offtin(header+16);
	if(newsize<0)
		errx(1,"Corrupt patch\n");

	/* Close patch file and re-open it via libbzip2 at the right places */
	if(((fd=open(oldFile.c_str(),O_RDONLY,0))<0) ||
		((oldsize=lseek(fd,0,SEEK_END))==-1) ||
		((old=malloc(oldsize+1))==NULL) ||
		(lseek(fd,0,SEEK_SET)!=0) ||
		(read(fd,old,oldsize)!=oldsize) ||
		(fstat(fd, &sb)) ||
       (close(fd)==-1)) err(1,"%s",oldFile.c_str());
	if((_new=malloc(newsize+1))==NULL) err(1,NULL);

	if (NULL == (bz2 = BZ2_bzReadOpen(&bz2err, f, 0, 0, NULL, 0)))
		errx(1, "BZ2_bzReadOpen, bz2err=%d", bz2err);

	stream.read = bz2_read;
	stream.opaque = bz2;
	if (bspatch(old, oldsize, _new, newsize, &stream))
		errx(1, "bspatch");

	/* Clean up the bzip2 reads */
	BZ2_bzReadClose(&bz2err, bz2);
	fclose(f);

	/* Write the new file */
	if(((fd=open(newFile.c_str(),O_CREAT|O_TRUNC|O_WRONLY,sb.st_mode))<0) ||
		(write(fd,_new,newsize)!=newsize) || (close(fd)==-1))
		err(1,"%s",newFile.c_str());

	free(_new);
	free(old);
}
TV_NAME_SPACE_END
