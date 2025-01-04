#include "../include/engine_window.h"

EngineWindow::EngineWindow()
{
    InitWindow();
}

GLFWwindow* EngineWindow::GetGlfwWindow()
{
    return glf_window;
}

void EngineWindow::InitWindow(uint32_t width, uint32_t height)
{
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glf_window = glfwCreateWindow(width, height, "RamEngine", nullptr, nullptr);
}
