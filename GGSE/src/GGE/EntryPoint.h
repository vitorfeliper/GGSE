#pragma once

#ifdef GGE_PLATFORM_WINDOWS

extern GGSE::Application* GGSE::CreateApplication();

int main(int argc, char** argv)
{
    printf("GanjGame Engine!!\n");

    auto app = GGSE::CreateApplication();

    app->Run();
    delete app;
}

#endif // GGE_PLATFORM_WINDOWS

