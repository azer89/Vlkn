#ifndef __HELLO_TRIANGLE_APPLICATION_H__
#define __HELLO_TRIANGLE_APPLICATION_H__

#ifndef GLFW_INCLUDE_VULKAN
#define GLFW_INCLUDE_VULKAN
#endif

#include <GLFW/glfw3.h>

#include <vector>

#include "Vertex.h"
#include "UniformBufferObject.h"
#include "QueueFamilyIndices.h"
#include "SwapChainSupportDetails.h"

const std::vector<const char*> validationLayers =
{
    "VK_LAYER_KHRONOS_validation"
};

const std::vector<const char*> deviceExtensions =
{
    VK_KHR_SWAPCHAIN_EXTENSION_NAME
};

//#ifdef NDEBUG
//const bool enableValidationLayers = false;
//#else
const bool enableValidationLayers = true;
//#endif

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

const int MAX_FRAMES_IN_FLIGHT = 2;

const std::vector<Vertex> vertices = 
{
    {{-0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}},
    {{0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}},
    {{0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}},
    {{-0.5f, 0.5f}, {1.0f, 1.0f, 1.0f}}
};

const std::vector<uint16_t> indices = 
{
    0, 1, 2, 2, 3, 0
};

class HelloTriangleApplication
{
private:
    GLFWwindow* window;

    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;
    VkSurfaceKHR surface; // Interface to the window system

    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE; // Physical device
    VkDevice device; // Logical device

    VkQueue graphicsQueue; // Obtained through vkGetDeviceQueue()
    VkQueue presentQueue;

    // Swap chain,  a queue of images that are waiting to be presented to the screen
    VkSwapchainKHR swapChain;
    std::vector<VkImage> swapChainImages;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;
    std::vector<VkImageView> swapChainImageViews;
    std::vector<VkFramebuffer> swapChainFramebuffers;

    // Pipeline
    VkRenderPass renderPass;
    VkDescriptorSetLayout descriptorSetLayout;
    VkPipelineLayout pipelineLayout;
    VkPipeline graphicsPipeline;

    // Command
    VkCommandPool commandPool;
    std::vector<VkCommandBuffer> commandBuffers;

    // Vertex buffer
    VkBuffer vertexBuffer;
    VkDeviceMemory vertexBufferMemory;

    // Index buffer
    VkBuffer indexBuffer;
    VkDeviceMemory indexBufferMemory;

    // Uniform buffer
    std::vector<VkBuffer> uniformBuffers;
    std::vector<VkDeviceMemory> uniformBuffersMemory;

    VkDescriptorPool descriptorPool;
    std::vector<VkDescriptorSet> descriptorSets;

    // Are used to add order between queue operations
    std::vector<VkSemaphore> imageAvailableSemaphores;
    std::vector<VkSemaphore> renderFinishedSemaphores;
    // For ordering the execution on the CPU/host
    std::vector<VkFence> inFlightFences;
    uint32_t currentFrame = 0;

    bool framebufferResized = false;

    // Texture
    VkImage textureImage;
    VkDeviceMemory textureImageMemory;

public:
    void run();

private:
    void initWindow();
    void initVulkan();
    void mainLoop();
    void createInstance();
    void cleanup(); // After the window is closed 

    void cleanupSwapChain();
    void recreateSwapChain();

    // Physical devices
    // Select a graphics card
    void pickPhysicalDevice(); 
    void createLogicalDevice();
    // If any of the physical devices meet the requirements
    bool isDeviceSuitable(VkPhysicalDevice device);
    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

    // Window surface
    void createSurface();

    // Swap chain
    void createSwapChain();
    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
    VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
    bool checkDeviceExtensionSupport(VkPhysicalDevice device);

    // Image views
    void createImageViews();

    // Pipeline
    void createGraphicsPipeline();
    VkShaderModule createShaderModule(const std::vector<char>& code);
    void createRenderPass();
    void createFramebuffers();

    // Command
    void createCommandPool();
    void createCommandBuffers();
    void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);

    // Texture
    void createTextureImage();
    void createImage(uint32_t width, uint32_t height, VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage, VkMemoryPropertyFlags properties, VkImage& image, VkDeviceMemory& imageMemory);
    void transitionImageLayout(VkImage image, VkFormat format, VkImageLayout oldLayout, VkImageLayout newLayout);
    void copyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height);

    // Vertex buffer
    void createVertexBuffer();
    void createBuffer(VkDeviceSize size, 
        VkBufferUsageFlags usage, 
        VkMemoryPropertyFlags properties, 
        VkBuffer& buffer, 
        VkDeviceMemory& bufferMemory);
    VkCommandBuffer beginSingleTimeCommands();
    void endSingleTimeCommands(VkCommandBuffer commandBuffer);
    void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);
    uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);

    // Index buffer
    void createIndexBuffer();

    // Uniform buffer
    void createDescriptorSetLayout();
    void createUniformBuffers();
    void updateUniformBuffer(uint32_t currentImage);

    void createDescriptorPool();
    void createDescriptorSets();

    void createSyncObjects();
    void drawFrame();

    // Validation layer
    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
    void setupDebugMessenger();
    std::vector<const char*> getRequiredExtensions();
    bool checkValidationLayerSupport();
    VkResult CreateDebugUtilsMessengerEXT(VkInstance instance,
        const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkDebugUtilsMessengerEXT* pDebugMessenger);
    void DestroyDebugUtilsMessengerEXT(VkInstance instance,
        VkDebugUtilsMessengerEXT debugMessenger,
        const VkAllocationCallbacks* pAllocator);

// Static functions
private:
    // Swap chain recreation
    static void framebufferResizeCallback(GLFWwindow* window, int width, int height);

    // Validation layer
    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
        VkDebugUtilsMessageTypeFlagsEXT messageType,
        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
        void* pUserData);
};

#endif