#include <iostream>

#include "HelloTriangleApplication.h"

int main()
{
    HelloTriangleApplication app;

    try 
    {
        std::cout << "Try run\n";
        app.run();
    }
    catch (const std::exception& e) 
    {
        std::cout << "Catch error\n";
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "Success\n";
    return EXIT_SUCCESS;
}