#include "Patcher.h"
#include "Updater.h"
#include "Environment.h"
#include <Poco/Path.h>
#include <Poco/File.h>
#include <Poco/Process.h>
#include <iostream>
using namespace std;
TV_NAME_SPACE_BEGIN
void Updater::Update( std::string _patchFile )
{
    auto args = Environment::GetInstance().getArgs();
    Poco::Path thisApp(args[0]);
    auto patchPath = thisApp.parent();
    patchPath.append("pat");
    cout<<patchPath.absolute().toString()<<endl;
    Poco::File patchFile(_patchFile);
    Poco::File newAppFile(thisApp.absolute().toString()+"_new");
    cout<<newAppFile.path()<<endl;
    if(patchFile.exists())
    {
        Patcher::getInstance().DoPatch(thisApp.toString(),newAppFile.path(),patchPath.toString());
    }
    newAppFile.setExecutable(true);
    auto foo = Poco::Process::launch(newAppFile.path(),{});
}
TV_NAME_SPACE_END
