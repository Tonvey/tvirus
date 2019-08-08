#include <iostream>
#include "Application.h"
using namespace std;
TV_USING_NAME_SPACE
int main(int argc , char **argv)
{
    //#if defined(POCO_OS_FAMILY_WINDOWS)
    //    cout<<"windows"<<endl;
    //#elif defined(POCO_OS_FAMILY_UNIX)
    //    cout<<"unix"<<endl;
    //#elif defined(POCO_OS_FAMILY_LINUX)
    //    cout<<"linux"<<endl;
    //#else
    //    cout<<"Unsupport platform"<<endl;
    //#endif
    //Logger::GetInstance().Info(Environment::osName());
    //Updater::GetInstance().Update("./pat");
    Application app(argc,argv);
    return app.run();
}
