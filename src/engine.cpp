#include "../include/engine.h"

Engine::Engine(EngineParams engine_params) {
	params_ = engine_params;
	engine_window_ = new EngineWindow();
}

void Engine::run() {
	initVulkan();
	mainLoop();
	cleanup();
}

void Engine::initVulkan() {
	instance_ = new VulkanInstance();
	instance_->createInstance();
	instance_->pickPhysicalDevice();
	instance_->createLogicalDevice();
	instance_->createGraphicsPipeline();
}

void Engine::mainLoop() {
	while (!glfwWindowShouldClose(engine_window_->GetGlfwWindow())) {
		glfwPollEvents();
	}
}

void Engine::cleanup() {
	instance_->cleanup();
	glfwDestroyWindow(engine_window_->GetGlfwWindow());
	glfwTerminate();
}
