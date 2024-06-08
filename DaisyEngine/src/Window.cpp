#include "Window.h"
#include <Log.h>

namespace Daisy
{

	Window::Window(const char* windowName, int w, int h)
	{
        if (!glfwInit())
        {
            std::cerr << "Failed to initialize GLFW" << std::endl;
        }
        windowWidth = w;
        windowHeight = h;
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_RESIZABLE, 0);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        Debug::Log("Creating Window");
        window = glfwCreateWindow(w, h, windowName, nullptr, nullptr);
        if (!window)
        {
            std::cerr << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
        }
        
        glfwSetWindowSizeCallback(window, ResizeCallback);

        glfwMakeContextCurrent(window);

        if (glewInit() != GLEW_OK)
        {
            Debug::LogError("Failed to initialize GLEW");
        }
        
        glEnable(GL_BLEND);
        glEnable(GL_DEPTH_TEST);
        //glBlendFunc(GL_SRC_ALPHA, GL_ONE);
        //glBlendFunc(GL_ONE, GL_ONE);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	bool Window::ShouldClose()
	{
		return glfwWindowShouldClose(window);
	}

    glm::vec2 Window::GetMousePosition()
    {
        double x;
        double y;
        glfwGetCursorPos(window, &x, &y);
        return glm::vec2(x,y);
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

    bool Window::GetMouseDown(int button)
    {
        return glfwGetMouseButton(window, button) == GLFW_PRESS;
    }

    bool Window::GetMouseUp(int button)
    {
        return glfwGetMouseButton(window, button) == GLFW_RELEASE;
    }

    namespace KeyInput
    {
        bool GetKeyDown(Daisy::Window window, int key)
        {
            return glfwGetKey(window.window, key) == GLFW_PRESS;
        }

        bool GetKeyUp(Daisy::Window window, int key)
        {
            return glfwGetKey(window.window, key) == GLFW_RELEASE;
        }
    }

    void ResizeCallback(GLFWwindow* window, int width, int height)
    {
        windowResized = true;
        windowWidth = width;
        windowHeight = height;
    }

    double Window::GetTime()
    {
        return glfwGetTime();
    }
}