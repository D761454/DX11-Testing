#include <Windows.h>
#include "Window.h"

LRESULT CALLBACK WinProc(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam) {

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
	CreateWindow("DX11Test", "DX11Test before uni", 
		WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_VISIBLE, 
		100, 100, width, height, 
		nullptr, nullptr, nullptr, nullptr);
}