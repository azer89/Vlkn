#ifndef __QUEUE_FAMILY_INDICES_H__
#define __QUEUE_FAMILY_INDICES_H__

#include <optional>

struct QueueFamilyIndices 
{
    std::optional<uint32_t> graphicsFamily;

    bool isComplete() 
    {
        return graphicsFamily.has_value();
    }
};

#endif