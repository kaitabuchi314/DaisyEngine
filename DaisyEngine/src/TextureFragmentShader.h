#pragma once

namespace Daisy
{
inline const char* textureFragmentShaderSource = // fragment shader
        R"(
    #version 330 core
    out vec4 FragColor;
    in vec2 TexCoord;
    uniform sampler2D texture1;

    void main()
    {
        FragColor = texture(texture1, TexCoord);
        //FragColor = vec4(255,0,0,255);
    }
)";

}