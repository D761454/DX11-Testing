#include "Renderer.h"

Renderer::Renderer(Window& window) {
	createDevice(window);
	createRenderTarget();
}

void Renderer::createDevice(Window& window) {
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

void Renderer::createRenderTarget() {
	ID3D11Texture2D* backBuffer;
	m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**) & backBuffer); // cast to void
	m_device->CreateRenderTargetView(backBuffer, nullptr, &m_renderTargetView);

	backBuffer->GetDesc(&m_backBufferDesc); // get info for window
	backBuffer->Release();
}

void Renderer::beginFrame() {
	// bind render target
	m_deviceContext->OMSetRenderTargets(1, &m_renderTargetView, nullptr);
	
	// set viewport
	auto viewport = CD3D11_VIEWPORT(0.f, 0.f, (float)m_backBufferDesc.Width, (float)m_backBufferDesc.Height);
	m_deviceContext->RSSetViewports(1, &viewport);

	// set bg colour
	float clearColor[] = { .25f, .5f, 1, 1 };
	m_deviceContext->ClearRenderTargetView(m_renderTargetView, clearColor);
}

void Renderer::endFrame() {
	// swap buffer
	m_swapChain->Present(1, 0);
}

ID3D11Device* Renderer::getDevice() {
	return m_device;
}

ID3D11DeviceContext* Renderer::getDeviceContext() {
	return m_deviceContext;
}