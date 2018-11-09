#include "stdafx.h"
#include "resource.h"

// Глобальные переменные:
HINSTANCE hInst;								// текущий экземпляр
TCHAR szTitle[MAX_LOADSTRING];					// Текст строки заголовка
TCHAR szWindowClass[MAX_LOADSTRING];			// имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: разместите код здесь.
	MSG msg;
	HACCEL hAccelTable;


	// Инициализация глобальных строк
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_GR3, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Выполнить инициализацию приложения:
	if (!InitInstance (hInstance, nCmdShow)) {
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GR3));

	// Цикл основного сообщения:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GR3));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_GR3);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

int XWndSize=800, YWndSize=800; //разрешание окна

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)//ф-ия. для создания окна
{
   HWND hWnd;
   hInst = hInstance;

   hWnd = CreateWindow(
	   szWindowClass,  
	   L"CG-LAB3. Strakhov-16VV3", 
	   WS_OVERLAPPEDWINDOW,
	   GetSystemMetrics(SM_CXSCREEN)/2-XWndSize/2, //задаем позицию угла окна по Х
	   GetSystemMetrics(SM_CYSCREEN)/2-YWndSize/2, //задаем позицию угла окна по У
	   XWndSize, YWndSize,
	   NULL, NULL, 
	   hInstance, NULL); 

   if (!hWnd)
	   return FALSE;

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);
   return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	switch (message){
		case WM_CREATE:
			{
			CreateWindowEx (WS_EX_CLIENTEDGE, TEXT("Edit"), TEXT("Outpu field..."), WS_CHILD | WS_VISIBLE | WS_BORDER, 200, 50, 300, 100, hWnd, NULL, NULL, NULL);
			CreateWindowEx (WS_EX_CLIENTEDGE,L"BUTTON", L"OK",  WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 10, 100, 100, hWnd, ( HMENU )BTN_PUSH, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);  
			break;
			}
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			
			EndPaint(hWnd, &ps);
			break;
		case WM_DESTROY: 
		PostQuitMessage(0); 
		break;
		default: return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
