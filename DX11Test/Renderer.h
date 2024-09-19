#pragma once
#include "Window.h"
#include <d3d11.h>

class Renderer
{
public:
	Renderer(Window& window);

private:
	IDXGISwapChain* m_swapChain = nullptr;
	ID3D11Device* m_device = nullptr; // use to make resources
	ID3D11DeviceContext* m_deviceContext = nullptr; // use to render
};

