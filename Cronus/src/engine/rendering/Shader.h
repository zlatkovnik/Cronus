#pragma once

#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>

#include <string>

class Shader
{
public:
    unsigned int m_id;
    Shader(const char* vertexPath, const char* fragmentPath);
    void Use();
    void SetBool(const std::string& name, bool value) const;
    void SetInt(const std::string& name, int value) const;
    void SetFloat(const std::string& name, float value) const;
    void SetMat4(const std::string& name, glm::mat4& mat) const;

private:
    void CheckCompileErrors(unsigned int shader, std::string type);
};