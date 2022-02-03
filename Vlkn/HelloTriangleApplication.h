#ifndef __HELLO_TRIANGLE_APPLICATION_H__
#define __HELLO_TRIANGLE_APPLICATION_H__

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <vector>

class HelloTriangleApplication
{
private:
    GLFWwindow* window;

    VkInstance instance;

    const uint32_t WIDTH = 800;
    const uint32_t HEIGHT = 600;

public:
    void run();

private:
    void initWindow();

    void initVulkan();

    void mainLoop();

    void cleanup();

    void createInstance();
};

#endif
