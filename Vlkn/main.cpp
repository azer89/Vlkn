/*#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>*/

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