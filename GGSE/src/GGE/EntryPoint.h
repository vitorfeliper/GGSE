#pragma once

#ifdef GGE_PLATFORM_WINDOWS

extern GGSE::Application* GGSE::CreateApplication();

int main(int argc, char** argv)
{
    printf("GanjGame Engine!!\n");

    GGSE::Log::Init();
    GGS_CORE_WARN("Initialized log!! :D");
    int a = 5;
    GGS_CLIENT_INFO("Hello!!! Var={0}", a);

    auto app = GGSE::CreateApplication();
    app->Run();
    delete app;
}

#endif // GGE_PLATFORM_WINDOWS

