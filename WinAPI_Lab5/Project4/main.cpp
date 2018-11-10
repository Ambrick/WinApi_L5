#include "header.h"
#include "Project4.h"


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId	= LOWORD(wParam),
		wmEvent = HIWORD(wParam);


	if (flow_control)
	{
		//if (autoit = commands.find(wmId))
		for (const auto& going_through : commands) {
			if (going_through.first == wmId) {
				string str = going_through.second + " ( WPARAM= " + to_string(going_through.first)+")\r\n";
				char *tab2 = new char[str.length() + 1];
				strcpy(tab2, str.c_str());

				const char* msg = tab2;
				wchar_t *wmsg = new wchar_t[strlen(msg) + 1];
				mbstowcs(wmsg, msg, strlen(msg) + 1);

				SendMessage(box_out, EM_REPLACESEL, (WPARAM)0, (LPARAM)wmsg);
				break;
			}
		}

	}
    switch (message) {
	case WM_CREATE:
		{
			btn = CreateWindowEx(NULL,
				L"BUTTON", L"Контроль вывода",
				WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
				10, 10, 400, 30,
				hWnd, (HMENU)BTN_PUSH, GetModuleHandle(NULL), NULL);

			box_out = CreateWindowEx(NULL,
				L"Edit", NULL,
				WS_CHILD | WS_VISIBLE |
				WS_BORDER | ES_LEFT | ES_MULTILINE | WS_EX_RTLREADING | WS_EX_STATICEDGE |
				ES_AUTOHSCROLL | ES_AUTOVSCROLL,
				10, 50, 400, 500,
				hWnd, (HMENU)TEXTBOX, GetModuleHandle(NULL), NULL);

			break;
		}
    case WM_COMMAND:
	{
		switch (wmId) {
		case BTN_PUSH:
		{
			flow_control = !flow_control;
			if (flow_control)
				SendMessage(box_out, EM_REPLACESEL, (WPARAM)0, (LPARAM)_T("Output is started\r\n"));
			if (!flow_control)
				SendMessage(box_out, EM_REPLACESEL, (WPARAM)0, (LPARAM)_T("Output is stoped\r\n"));
			break;
		}
		case IDM_EXIT:
		{
			DestroyWindow(hWnd);
			break;
		}
		break;
		}
	}
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJECT4));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_PROJECT4);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

	int XWndSize = 440, YWndSize = 600; //разрешание окна

	HWND hWnd = CreateWindow(
		szWindowClass,
		L"WinApi_L5:Strakhov,Samushkin",
		WS_OVERLAPPEDWINDOW,
		GetSystemMetrics(SM_CXSCREEN) / 2 - XWndSize / 2, //задаем позицию угла окна по Х
		GetSystemMetrics(SM_CYSCREEN) / 2 - YWndSize / 2, //задаем позицию угла окна по У
		XWndSize, YWndSize,
		NULL, NULL,
		hInstance, NULL);

	if (!hWnd)
		return FALSE;

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return TRUE;
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// Инициализация глобальных строк
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_PROJECT4, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Выполнить инициализацию приложения:
	if (!InitInstance(hInstance, nCmdShow))
		return FALSE;

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PROJECT4));
	MSG msg;

	// Цикл основного сообщения:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}