#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include <STB/stb_image.h>

#include <iostream>
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

std::unordered_map<std::string, unsigned int> Texture::m_loadedTextures;


Texture::Texture(const char filePath[])
{
    if (m_loadedTextures.find(filePath) == m_loadedTextures.end()) {
        m_id = LoadTexture(filePath);
        m_loadedTextures[filePath] = m_id;
    } else {
        m_id = m_loadedTextures[filePath];
    }
}

Texture::~Texture()
{
    //glDeleteTextures(1, &m_id);
}

void Texture::Bind(int texIndex)
{
    glActiveTexture(GL_TEXTURE0 + texIndex);
    glBindTexture(GL_TEXTURE_2D, m_id);
}

unsigned int Texture::LoadTexture(const char filePath[])
{
    unsigned int ID;
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);

    unsigned char* data = stbi_load(filePath, &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
    return ID;
}
