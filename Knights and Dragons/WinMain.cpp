#include <windows.h>
#include<sstream>
#include "Window.h"
#include "WindowsMessageMap.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nCmdShow)
{
	Window* wnd;

	//messages
	MSG msg;
	int gResult = -1;
	try {
		wnd = new Window(1280, 720, "Knights and Dragons");

		while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);	
		}
		if (gResult != -1) {
			gResult = msg.wParam;
		}
	}
	catch (const Exceptions& e) {
		MessageBox(nullptr, e.what(), e.getType(), MB_OK|MB_ICONEXCLAMATION);
	}
	catch (const std::exception e) {
		MessageBox(nullptr, e.what(), "Standard exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...) {
		MessageBox(nullptr, "No details avaliable", "Unknown exception", MB_OK | MB_ICONEXCLAMATION);
	}
	return gResult;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	static WindowsMessageMap mm;
	OutputDebugString(mm(msg, lParam, wParam).c_str());

	switch (msg) {
	case WM_CLOSE:
		PostQuitMessage(34);
		break;
	case WM_KEYDOWN:
		if (wParam == 'F') {
			SetWindowText(hWnd, "woo");
			break;
		}
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}