#pragma once

#include <GLFW/glfw3.h>

class EngineWindow
{
public:
    GLFWwindow* glf_window;
    EngineWindow();
    GLFWwindow* GetGlfwWindow();

private:
    void InitWindow(uint32_t width = 800, uint32_t height = 600);
};
