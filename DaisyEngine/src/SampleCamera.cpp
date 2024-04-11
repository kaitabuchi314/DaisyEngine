#include "SampleCamera.h"

namespace Daisy
{
    void SampleMoveCamera(Daisy::Camera* camera, Daisy::Window window)
    {
        float cameraSpeed = 0.0008f;
        float cameraRotSpeed = 0.025f;

        if (glfwGetKey(window.window, GLFW_KEY_W) == GLFW_PRESS)
            camera->cameraPos += cameraSpeed * camera->cameraFront;
        if (glfwGetKey(window.window, GLFW_KEY_S) == GLFW_PRESS)
            camera->cameraPos -= cameraSpeed * camera->cameraFront;
        if (glfwGetKey(window.window, GLFW_KEY_Q) == GLFW_PRESS)
            camera->cameraPos += cameraSpeed * camera->cameraUp;
        if (glfwGetKey(window.window, GLFW_KEY_E) == GLFW_PRESS)
            camera->cameraPos -= cameraSpeed * camera->cameraUp;
        if (glfwGetKey(window.window, GLFW_KEY_A) == GLFW_PRESS)
            camera->cameraPos -= glm::normalize(glm::cross(camera->cameraFront, camera->cameraUp)) * cameraSpeed;
        if (glfwGetKey(window.window, GLFW_KEY_D) == GLFW_PRESS)
            camera->cameraPos += glm::normalize(glm::cross(camera->cameraFront, camera->cameraUp)) * cameraSpeed;

        if (glfwGetKey(window.window, GLFW_KEY_LEFT) == GLFW_PRESS)
            camera->cameraFront = glm::mat3(glm::rotate(glm::mat4(1.0f), glm::radians(cameraRotSpeed), camera->cameraUp)) * camera->cameraFront;
        if (glfwGetKey(window.window, GLFW_KEY_RIGHT) == GLFW_PRESS)
            camera->cameraFront = glm::mat3(glm::rotate(glm::mat4(1.0f), glm::radians(-cameraRotSpeed), camera->cameraUp)) * camera->cameraFront;
        if (glfwGetKey(window.window, GLFW_KEY_UP) == GLFW_PRESS)
            camera->cameraFront = glm::mat3(glm::rotate(glm::mat4(1.0f), glm::radians(cameraRotSpeed), glm::normalize(glm::cross(camera->cameraFront, camera->cameraUp)))) * camera->cameraFront;
        if (glfwGetKey(window.window, GLFW_KEY_DOWN) == GLFW_PRESS)
            camera->cameraFront = glm::mat3(glm::rotate(glm::mat4(1.0f), glm::radians(-cameraRotSpeed), glm::normalize(glm::cross(camera->cameraFront, camera->cameraUp)))) * camera->cameraFront;
    }
}