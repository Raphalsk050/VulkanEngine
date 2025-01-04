#pragma once
#include <vulkan/vulkan_core.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <cstring>
#include <vector>


class VulkanInstance
{
private:
    VkInstance instance;

public:
    VkResult createInstance();
    bool checkValidationLayerSupport();
    void cleanup();

    const std::vector<const char*> validationLayers = {
        "VK_LAYER_KHRONOS_validation"
    };

#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif
};
