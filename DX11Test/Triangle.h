#pragma once
#include "Renderer.h"

class Triangle
{
public:
	Triangle(Renderer& renderer);
	~Triangle();
	void draw(Renderer& renderer);
private:
	void createMesh(Renderer& renderer);
	void createShaders(Renderer& renderer);

	ID3D11Buffer* m_vertexBuffer = nullptr;
	ID3D11VertexShader* m_vertexShader = nullptr;
	ID3D11PixelShader* m_pixelShader = nullptr;
};

