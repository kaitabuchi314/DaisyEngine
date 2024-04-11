#include "Window.h"

namespace Daisy
{
	Window::Window(const char* windowName, int w, int h)
	{
        if (!glfwInit())
        {
            std::cerr << "Failed to initialize GLFW" << std::endl;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(w, h, windowName, nullptr, nullptr);
        if (!window)
        {
            std::cerr << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
        }
        glfwMakeContextCurrent(window);

        if (glewInit() != GLEW_OK)
        {
            std::cerr << "Failed to initialize GLEW" << std::endl;
        }

        glEnable(GL_BLEND);
        glEnable(GL_DEPTH_TEST);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	bool Window::ShouldClose()
	{
		return glfwWindowShouldClose(window);
	}

    glm::vec2 Window::GetSize()
    {
        int w;
        int h;
        glfwGetWindowSize(window, &w, &h);
        return glm::vec2(w, h);
    }

    void Window::EndFrame()
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    void Window::Terminate()
    {
        glfwTerminate();
    }
}