#include <iostream>
#include <cstdlib> // EXIT_SUCCESS and EXIT_FAILURE macros

#include "HelloTriangleApplication.h"

int main()
{
    HelloTriangleApplication app;

    try 
    {
        app.run();
    }
    catch (const std::exception& e) 
    {
        std::cout << "Catch error on main(): \n";
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}