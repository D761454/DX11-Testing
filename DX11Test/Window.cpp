#include "Window.h"

LRESULT CALLBACK WinProc(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam) {

	if (msg == WM_DESTROY ||
		msg == WM_CLOSE) {
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(handle, msg, wparam, lparam);
}

Window::Window(int width, int height) {
	// define windows style
	WNDCLASS wc = { 0 };
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WinProc;
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.lpszClassName = "DX11Test";
	RegisterClass(&wc);

	// create window
	m_handle = CreateWindow("DX11Test", "DX11Test before uni", 
		WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_VISIBLE | WS_MINIMIZEBOX | WS_MAXIMIZEBOX, 
		100, 100, width, height, 
		nullptr, nullptr, nullptr, nullptr);
}

HWND Window::getHandle() {
	return m_handle;
}