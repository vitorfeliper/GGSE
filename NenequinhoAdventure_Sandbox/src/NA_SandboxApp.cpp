#include <GanjGameEngine.h>

class NA_Sandbox : public GGSE::Application
{
public:
    NA_Sandbox() 
    {

    }

    ~NA_Sandbox()
    {

    }


};

GGSE::Application* GGSE::CreateApplication()
{
    return new NA_Sandbox();
}