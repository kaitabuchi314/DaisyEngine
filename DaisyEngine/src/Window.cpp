#include "Window.h"

namespace Daisy
{
	Window::Window(int width, int height, std::string title)
	{
        if (!glfwInit()) {
            std::cerr << "Failed to initialize GLFW" << std::endl;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(1350, 900, title.c_str(), nullptr, nullptr);
        if (!window) {
            std::cerr << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
        }

        glfwMakeContextCurrent(window);

        glfwSetKeyCallback(window, Input::key_callback);
	}

    void Window::EndFrame()
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    void Window::Flush()
    {
        glfwTerminate();
    }

    bool Window::WindowClosed()
    {
        return glfwWindowShouldClose(window);
    }
};