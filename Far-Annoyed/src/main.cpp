#include <iostream>
#include <string.h>

#include "Application.h"

int main()
{
    try
    {
        auto *app = new Breaker::Application;

        app->Run();

        delete app;
    }
    catch (const std::exception &e)
    {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
    catch (...)
    {
        char buffer[256];

        #ifdef WIN32
            strerror_s(buffer, sizeof(buffer), errno);
        #else
            strerror_r(errno, buffer, sizeof(buffer));
        #endif

        std::cerr << "Error [ " << errno << " ]: " << buffer << std::endl;
    }

    // auto* app = new Breaker::Application; app->Run();

    return 0;
}