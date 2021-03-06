#ifndef __SWAP_CHAIN_SUPPORT_DETAILS_H__
#define __SWAP_CHAIN_SUPPORT_DETAILS_H__

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <vector>

// Is used when calling vkGetPhysicalDeviceSurfaceCapabilitiesKHR
struct SwapChainSupportDetails 
{
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};

#endif