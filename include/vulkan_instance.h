#pragma once
#include <vulkan/vulkan_core.h>
#include <GLFW/glfw3.h>
#include <stdexcept>


class VulkanInstance
{
private:
    VkInstance instance;


public:
    VkResult createInstance();
    void cleanup();
};
