#pragma once

#include <cstdint>
#include "engine_window.h"
#include "vulkan_instance.h"

struct EngineParams {
    uint32_t width = 800;
    uint32_t height = 600;
};

class Engine {
public:
    Engine(EngineParams engine_params = EngineParams());

    void run();

private:
    EngineWindow *engine_window_;
    VulkanInstance *instance_;
    EngineParams params_;

    void initVulkan();

    void mainLoop();

    void cleanup();
};
