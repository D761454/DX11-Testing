#include <Windows.h>
#include "Window.h"

Window::Window(int width, int height) {


	// create window
	CreateWindow("", "DX11Test", 
		WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_VISIBLE, 
		100, 100, width, height, 
		nullptr, nullptr, nullptr, nullptr);
}