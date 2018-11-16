#include "resource.h"

bool flow_control = true;
HWND box_out, btn;
map < int, string > commands = {
	//{0, "WM_NULL" },
	{3, "WM_MOVE" },
	{5, "WM_SIZE" },
	{6, "WM_ACTIVATE" },
	{7, "WM_SETFOCUS" },
	{8, "WM_KILLFOCUS" },
	{10, "WM_ENABLE" },
	{11, "WM_SETREDRAW" },
	{13, "WM_GETTEXT" },
	{14, "WM_GETTEXTLENGTH" },
	{17, "WM_QUERYENDSESSION" },
	{18, "WM_SHOWWINDOW" },
	{19, "WM_QUERYOPEN" },
	{20, "WM_ERASEBKGND" },
	{21, "WM_SYSCOLORCHANGE" },
	{24, "WM_SHOWWINDOW" },
	{25, "WM_CTLCOLOR" },
	{26, "WM_WININICHANGE" },
	{27, "WM_DEVMODECHANGE" },
	{28, "WM_ACTIVATEAPP" },
	{29, "WM_FONTCHANGE" },
	{30, "WM_TIMECHANGE" },
	{31, "WM_CANCELMODE" },
	{32, "WM_SETCURSOR" },
	{33, "WM_MOUSEACTIVATE" },
	{34, "WM_CHILDACTIVATE" },
	{35, "WM_QUEUESYNC" },
	{36, "WM_GETMINMAXINFO" },
	{38, "WM_PAINTICON" },
	{39, "WM_ICONERASEBKGND" },
	{74, "WM_COPYDATA" },
	{256 ,"WM_KEYDOWN"},
	{769 ,"WM_COPY"},
	{512 ,"WM_MOUSEMOVE"},
	{513 ,"WM_LBUTTONDOWN"},
	{514 ,"WM_LBUTTONUP"},
	{518 ,"WM_LBUTTONDBLCLK"},
	{516 ,"WM_RBUTTONDOWN"},
	{517 ,"WM_RBUTTONUP"},
	{519 ,"WM_MBUTTONDOWN"},
	{520 ,"WM_MBUTTONUP"},
	{521 ,"WM_MBUTTONDBLCLK"},
	{522 ,"WM_MOUSEWHEEL"},
	{532, "WM_SIZING" },
	{533, "WM_CAPTURECHANGED" },
	{534, "WM_MOVING" },
};

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId = LOWORD(wParam);
	
	auto search = commands.find(wmId);
	if (commands.count(wmId) == 1 && flow_control) {

		string s_msg = search->second + " ( LOWORD(wParam) = " + to_string(search->first) + ")\r\n";
		char *c_msg = new char[s_msg.length() + 1];
		strcpy(c_msg, s_msg.c_str());

		wchar_t *w_msg = new wchar_t[strlen(c_msg) + 1];
		mbstowcs(w_msg, c_msg, strlen(c_msg) + 1);
		SendMessage(box_out, EM_REPLACESEL, 0, (LPARAM)w_msg);
	}

	switch (message) {
	case WM_CREATE:
	{
		btn = CreateWindowEx(NULL,
			L"BUTTON", L"Контроль вывода",
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			10, 10, 400, 30,
			hWnd, (HMENU) ID_BTN_PUSH, GetModuleHandle(NULL), NULL);

		box_out = CreateWindowEx(NULL,
			L"Edit", NULL,
			WS_CHILD | WS_VISIBLE |
			WS_BORDER | ES_LEFT | ES_MULTILINE | WS_EX_RTLREADING | WS_EX_STATICEDGE |
			ES_AUTOHSCROLL | ES_AUTOVSCROLL,
			10, 50, 400, 500,
			hWnd, (HMENU) ID_TEXTBOX, GetModuleHandle(NULL), NULL);

		break;
	}
	case WM_COMMAND:
	{
		if (wmId == ID_BTN_PUSH) {
			flow_control = !flow_control;
			if (flow_control)
				SendMessage(box_out, EM_REPLACESEL, (WPARAM)0, (LPARAM)_T("Запустить диспетчеризацию!\r\n"));
			else if (!flow_control)
				SendMessage(box_out, EM_REPLACESEL, (WPARAM)0, (LPARAM)_T("Остановить диспетчеризацию!\r\n"));
		}
		break;
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

HINSTANCE hInst;                      // текущий экземпляр
WCHAR szTitle[100];                  // Текст строки заголовка
WCHAR szWindowClass[100];            // имя класса главного окна

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DISPDIALOG));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_DISPDIALOG);
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

	if (!hWnd) return FALSE;
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return TRUE;
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance); UNREFERENCED_PARAMETER(lpCmdLine);

	// Инициализация глобальных строк
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_DISPDIALOG, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Выполнить инициализацию приложения:
	if (!InitInstance(hInstance, nCmdShow)) return FALSE;

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DISPDIALOG));
	MSG msg;

	// Цикл основного сообщения:
	while (GetMessage(&msg, nullptr, 0, 0)) {
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}