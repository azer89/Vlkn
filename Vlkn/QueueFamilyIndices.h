#ifndef __QUEUE_FAMILY_INDICES_H__
#define __QUEUE_FAMILY_INDICES_H__

#include <optional>

struct QueueFamilyIndices 
{
    // std::optional requires C++17
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    bool isComplete() 
    {
        return graphicsFamily.has_value() && presentFamily.has_value();
    }
};

#endif
