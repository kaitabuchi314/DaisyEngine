#include "Camera.h"

namespace Daisy
{
    Camera::Camera(glm::vec2 ws)
    {
        projection = glm::perspective(glm::radians(45.0f), (float)ws.x / (float)ws.y, 0.1f, 100.0f);

        cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
        cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
        cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
        view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

    }

    void Camera::CalcView()
    {
        view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
    }
}

