#pragma once
#include <vulkan/vulkan_core.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <cstring>
#include <map>
#include <optional>
#include <vector>

#define VK_USE_PLATFORM_WIN32_KHR
#define GLFW_INCLUDE_VULKAN
#define GLFW_EXPOSE_NATIVE_WIN32

struct QueueFamilyIndices
{
    std::optional<uint32_t> graphicsFamily;

    bool isComplete() {
        return graphicsFamily.has_value();
    }
};

class VulkanInstance
{
private:
    VkInstance instance;
    VkDevice device;
    VkQueue graphicsQueue;
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    bool isDeviceSuitable(VkPhysicalDevice device);
    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

public:
    VkResult createInstance();
    bool checkValidationLayerSupport();
    void cleanup();
    void pickPhysicalDevice();
    void createLogicalDevice();
    void createGraphicsPipeline();

    const std::vector<const char*> validationLayers = {
        "VK_LAYER_KHRONOS_validation"
    };

#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif
};
