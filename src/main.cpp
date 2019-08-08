#include <iostream>
#include <Poco/Foundation.h>
#include "Environment.h"
#include "Updater.h"
using namespace std;
TV_USING_NAME_SPACE
int main(int argc , char **argv)
{
    vector<string> args;
    args.reserve(argc);
    for(int i = 0 ;i<argc ; ++i)
    {
        args.push_back(argv[i]);
    }
    Environment::GetInstance().setArgs(args);
    args.clear();
    args.resize(0);
#if defined(POCO_OS_FAMILY_WINDOWS)
    cout<<"windows"<<endl;
#elif defined(POCO_OS_FAMILY_UNIX)
    cout<<"unix"<<endl;
#elif defined(POCO_OS_FAMILY_LINUX)
    cout<<"linux"<<endl;
#else
    cout<<"Unsupport platform"<<endl;
#endif
    cout<<Environment::osName()<<endl;
    Updater::GetInstance().Update("./pat");
    return 0;
}
