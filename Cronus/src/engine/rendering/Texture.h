#pragma once

#include <unordered_map>
#include <string>

class Texture
{
private:
	//TODO Hes mapa koja cuva kesirane teksture
	static std::unordered_map<std::string, unsigned int> m_loadedTextures;
	unsigned int m_id;
public:
	Texture(const char filePath[]);
	~Texture();
	void Bind(int texIndex);
private:
	static unsigned int LoadTexture(const char filePath[]);
};

