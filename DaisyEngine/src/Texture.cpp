#include "Texture.h"

namespace Daisy
{
	Texture::Texture(const std::string path)
	{
        stbi_set_flip_vertically_on_load(true);

        unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
        if (!data)
        {
            std::cerr << "Failed to load texture" << std::endl;
        }

        glGenTextures(1, &id);
        glBindTexture(GL_TEXTURE_2D, id);


        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        
        if (nrChannels == 3)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        }
        else if (nrChannels == 4)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        }
        std::cout << nrChannels << std::endl;

        glGenerateMipmap(GL_TEXTURE_2D);

        stbi_image_free(data);
	}

	void Texture::Bind()
	{
        glBindTexture(GL_TEXTURE_2D, id);
	}

	void Texture::Unbind()
	{
        glBindTexture(GL_TEXTURE_2D, 0);
	}

	void Texture::Flush()
	{
        glDeleteTextures(1, &id);
	}
}