#include "SampleCamera.h"
#include <Defines.h>

namespace Daisy
{
    void SampleMoveCamera(Daisy::Camera* camera, Daisy::Window window)
    {
        float cameraSpeed = 0.0008f;
        float cameraRotSpeed = 0.025f;

        if (KeyInput::GetKeyDown(window, DAISY_KEY_W))
            camera->cameraPos += cameraSpeed * camera->cameraFront;
        if (KeyInput::GetKeyDown(window, DAISY_KEY_S))
            camera->cameraPos -= cameraSpeed * camera->cameraFront;
        if (KeyInput::GetKeyDown(window, DAISY_KEY_Q))
            camera->cameraPos += cameraSpeed * camera->cameraUp;
        if (KeyInput::GetKeyDown(window, DAISY_KEY_E))
            camera->cameraPos -= cameraSpeed * camera->cameraUp;
        if (KeyInput::GetKeyDown(window, DAISY_KEY_A))
            camera->cameraPos -= glm::normalize(glm::cross(camera->cameraFront, camera->cameraUp)) * cameraSpeed;
        if (KeyInput::GetKeyDown(window, DAISY_KEY_D))
            camera->cameraPos += glm::normalize(glm::cross(camera->cameraFront, camera->cameraUp)) * cameraSpeed;

        if (KeyInput::GetKeyDown(window, DAISY_KEY_LEFT))
            camera->cameraFront = glm::mat3(glm::rotate(glm::mat4(1.0f), glm::radians(cameraRotSpeed), camera->cameraUp)) * camera->cameraFront;
        if (KeyInput::GetKeyDown(window, DAISY_KEY_RIGHT))
            camera->cameraFront = glm::mat3(glm::rotate(glm::mat4(1.0f), glm::radians(-cameraRotSpeed), camera->cameraUp)) * camera->cameraFront;
        if (KeyInput::GetKeyDown(window, DAISY_KEY_UP))
            camera->cameraFront = glm::mat3(glm::rotate(glm::mat4(1.0f), glm::radians(cameraRotSpeed), glm::normalize(glm::cross(camera->cameraFront, camera->cameraUp)))) * camera->cameraFront;
        if (KeyInput::GetKeyDown(window, DAISY_KEY_DOWN))
            camera->cameraFront = glm::mat3(glm::rotate(glm::mat4(1.0f), glm::radians(-cameraRotSpeed), glm::normalize(glm::cross(camera->cameraFront, camera->cameraUp)))) * camera->cameraFront;
    }

    
}