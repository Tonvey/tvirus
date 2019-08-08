#include "Patcher.h"
#include "bsdiff.h"
#include "bspatch.h"
#include <iostream>
#include <cstdint>
#include "bspatch.h"
using namespace std;
using namespace bs;
TV_NAME_SPACE_BEGIN
Patcher Patcher::smInstance;
Patcher::Patcher()
{
}
void Patcher::DoPatch(std::string oldFile,std::string newFile,std::string patchFile)
{
    string errMsg;
    int ret = BSPatch::Patch(oldFile,newFile,patchFile,errMsg);
    if(ret)
    {
        throw runtime_error(errMsg);
    }
}
void Patcher::DoDiff(std::string oldFile,std::string newFile,std::string patchFile)
{
    string errMsg;
    int ret = BSDiff::Diff(oldFile,newFile,patchFile,errMsg);
    if(ret)
    {
        throw runtime_error(errMsg);
    }
}
TV_NAME_SPACE_END
