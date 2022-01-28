#ifndef __HELLO_TRIANGLE_APPLICATION_H__
#define __HELLO_TRIANGLE_APPLICATION_H__

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>

//const uint32_t WIDTH = 800;
//const uint32_t HEIGHT = 600;

class HelloTriangleApplication
{
public:
    void run() 
    {
        initVulkan();
        mainLoop();
        cleanup();
    }

private:
    void initVulkan() 
    {
    }

    void mainLoop() 
    {
    }

    void cleanup() 
    {
    }

};

#endif
