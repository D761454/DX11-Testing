#include <Windows.h>
#include "Window.h"

int CALLBACK WinMain(HINSTANCE appInstance, HINSTANCE prevInstance, LPSTR cmdLine, int cmdCount) {

	Window window(800, 600);

	MSG msg = { 0 };
	while (true) {
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT) break;
		}

		// >>> Main Loop <<<
		// update
		// draw etc
	}

	return 0;
}