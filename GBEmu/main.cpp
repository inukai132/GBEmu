#include <Windows.h>
#include <tchar.h>

int GB_WIDTH = 160;
int GB_HEIGHT = 144;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void redraw(HDC hdc);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmd, int nCmdShow)
{
	int gb_mult = 5;
	static TCHAR CLASS_NAME[] = _T("GBEmu");
	WNDCLASS wc = {};

	wc.lpfnWndProc = WndProc;
	wc.hInstance = hInst;
	wc.lpszClassName = CLASS_NAME;

	if (!RegisterClass(&wc))
	{
		MessageBox(NULL,
			_T("Call to RegisterClass Failed!"),
			_T("Error Box"),
			NULL);

		return 1;
	}

	HWND hWnd = CreateWindowEx(0, CLASS_NAME, _T("GameBoy Emulator"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, gb_mult * GB_WIDTH, gb_mult * GB_HEIGHT, NULL, NULL, hInst, NULL);
	if (!hWnd)
	{
		DWORD er = GetLastError();
		MessageBox(NULL,
			_T("Call to CreateWindow Failed!"),
			_T("Error Box"),
			NULL);

		return 1;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		redraw(hdc);
		EndPaint(hWnd, &ps);
	case WM_CREATE:
		return 0;
	case WM_SIZE:
		return 0;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

void redraw(HDC hdc)
{
	TextOut(hdc, 10, 10, _T("Hello Wurld"), 12);

}
