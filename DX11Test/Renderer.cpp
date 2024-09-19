#include "Renderer.h"

Renderer::Renderer(Window& window) {
	// swap chain - like double buffering / back buffer - prevent tearing
	DXGI_SWAP_CHAIN_DESC swapChainDesc = { 0 };
	swapChainDesc.BufferCount = 1; // 1 back buffer
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.OutputWindow = window.getHandle();
	swapChainDesc.SampleDesc.Count = 1; // multisample / antialiasing
	swapChainDesc.Windowed = true;

	// create the swap chain, device and device context
	auto result = D3D11CreateDeviceAndSwapChain(
		nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0,
		nullptr, 0, D3D11_SDK_VERSION,
		&swapChainDesc, &m_swapChain, &m_device, nullptr, &m_deviceContext);

	// check for errors
	if (result != S_OK) {
		MessageBox(nullptr, "Problem Creating DX11", "Error", MB_OK);
		exit(0);
	}
}