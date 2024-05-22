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
        vec4 tex = texture(texture1, TexCoord);
        //if (tex.a > 0.5) {
        //    FragColor = tex;
        //} else {
            //FragColor = vec4(0,0,0,0);
        //}
        if(tex.a < 1)
            discard;
        FragColor = tex;
        //FragColor = vec4(255,0,0,tex.a);
    }
)";

}