#ifndef __VALIDATION_LAYER_H__
#define __VALIDATION_LAYER_H__

#include <vector>

const std::vector<const char*> validationLayers =
{
    "VK_LAYER_KHRONOS_validation"
};

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

#endif
