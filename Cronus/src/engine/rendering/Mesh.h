#pragma once
#include <vector>

class Mesh {
private:
	unsigned int m_vao, m_vbo, m_ebo;
	int m_vertexCount;
public:
	Mesh(std::vector<float>& vertices, std::vector<unsigned int> &indices);
	void Draw();
};

