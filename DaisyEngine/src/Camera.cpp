#include "Camera.h"

namespace Daisy
{
    Camera::Camera(glm::vec2 ws, bool perspective, Window window)
    {
        if (perspective)
            projection = glm::perspective(glm::radians(45.0f), (float)ws.x / (float)ws.y, 0.1f, 100.0f);
        else
        {
            glm::vec2 size = window.GetSize();
            float aspect = (float)size.x / size.y;
            projection = glm::ortho(-aspect, aspect, -1.0f, 1.0f, 0.001f, 100.0f);


        }
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

