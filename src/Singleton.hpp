#pragma once
#include "Macro.h"
TV_NAME_SPACE_BEGIN
template<class T>
class Singleton
{
public:
    static T &GetInstance()
    {
        static T smInstance;
        return smInstance;
    }
private:
    Singleton(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton& operator=(Singleton&&) = delete;
protected:
    Singleton(){};
    virtual ~Singleton() { }
};
TV_NAME_SPACE_END
