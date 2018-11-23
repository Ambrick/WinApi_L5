﻿#include "resource.h"

bool flow_control = true;
HWND box_out, cntrl, firstcmds;
map < int, string > commands = {
//{1, "WM_CREATE" },
//{2, "WM_DESTROY" },
{3, "WM_MOVE" },
{5, "WM_SIZE" },
{6, "WM_ACTIVATE" },
{7, "WM_SETFOCUS" },
//{8, "WM_KILLFOCUS" },
//{10, "WM_ENABLE" },
{11, "WM_SETREDRAW" },
//{12, "WM_SETTEXT" },
{13, "WM_GETTEXT" },
{14, "WM_GETTEXTLENGTH" },
{15, "WM_PAINT" },
{16, "WM_CLOSE" },
{17, "WM_QUERYENDSESSION" },
{18, "WM_QUIT" },
{19, "WM_QUERYOPEN" },
{20, "WM_ERASEBKGND" },
{21, "WM_SYSCOLORCHANGE" },
{22, "WM_ENDSESSION" },
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
{40, "WM_NEXTDLGCTL" },
{42, "WM_SPOOLERSTATUS" },
{43, "WM_DRAWITEM" },
{44, "WM_MEASUREITEM" },
{45, "WM_DELETEITEM" },
{46, "WM_VKEYTOITEM" },
{47, "WM_CHARTOITEM" },
{48, "WM_SETFONT" },
{49, "WM_GETFONT" },
{50, "WM_SETHOTKEY" },
{51, "WM_GETHOTKEY" },
{55, "WM_QUERYDRAGICON" },
{57, "WM_COMPAREITEM" },
{61, "WM_GETOBJECT" },
{65, "WM_COMPACTING" },
{68, "WM_COMMNOTIFY" },
{70, "WM_WINDOWPOSCHANGING" },
{71, "WM_WINDOWPOSCHANGED" },
{72, "WM_POWER" },
{73, "WM_COPYGLOBALDATA" },
{74, "WM_COPYDATA" },
{75, "WM_CANCELJOURNAL" },
{78, "WM_NOTIFY" },
{80, "WM_INPUTLANGCHANGEREQUEST" },
{81, "WM_INPUTLANGCHANGE" },
{82, "WM_TCARD" },
{83, "WM_HELP" },
{84, "WM_USERCHANGED" },
{85, "WM_NOTIFYFORMAT" },
{123, "WM_CONTEXTMENU" },
{124, "WM_STYLECHANGING" },
{125, "WM_STYLECHANGED" },
{126, "WM_DISPLAYCHANGE" },
{127, "WM_GETICON" },
{128, "WM_SETICON" },
{129, "WM_NCCREATE" },
{130, "WM_NCDESTROY" },
{131, "WM_NCCALCSIZE" },
{132, "WM_NCHITTEST" },
{133, "WM_NCPAINT" },
{134, "WM_NCACTIVATE" },
{135, "WM_GETDLGCODE" },
{136, "WM_SYNCPAINT" },
{160, "WM_NCMOUSEMOVE" },
{161, "WM_NCLBUTTONDOWN" },
{162, "WM_NCLBUTTONUP" },
{163, "WM_NCLBUTTONDBLCLK" },
{164, "WM_NCRBUTTONDOWN" },
{165, "WM_NCRBUTTONUP" },
{166, "WM_NCRBUTTONDBLCLK" },
{167, "WM_NCMBUTTONDOWN" },
{168, "WM_NCMBUTTONUP" },
{169, "WM_NCMBUTTONDBLCLK" },
{171, "WM_NCXBUTTONDOWN" },
{172, "WM_NCXBUTTONUP" },
{173, "WM_NCXBUTTONDBLCLK" },
{176, "EM_GETSEL" },
{177, "EM_SETSEL" },
{178, "EM_GETRECT" },
{179, "EM_SETRECT" },
{180, "EM_SETRECTNP" },
{181, "EM_SCROLL" },
{182, "EM_LINESCROLL" },
{183, "EM_SCROLLCARET" },
{185, "EM_GETMODIFY" },
{187, "EM_SETMODIFY" },
{188, "EM_GETLINECOUNT" },
{189, "EM_LINEINDEX" },
{190, "EM_SETHANDLE" },
{191, "EM_GETHANDLE" },
{192, "EM_GETTHUMB" },
{193, "EM_LINELENGTH" },
{194, "EM_REPLACESEL" },
{195, "EM_SETFONT" },
{196, "EM_GETLINE" },
{197, "EM_LIMITTEXT" },
{197, "EM_SETLIMITTEXT" },
{198, "EM_CANUNDO" },
{199, "EM_UNDO" },
{200, "EM_FMTLINES" },

{255, "WM_INPUT" },
{256, "WM_KEYDOWN" },
{256, "WM_KEYFIRST" },
{257, "WM_KEYUP" },
{258, "WM_CHAR" },
{259, "WM_DEADCHAR" },
{260, "WM_SYSKEYDOWN" },
{261, "WM_SYSKEYUP" },
{262, "WM_SYSCHAR" },
{263, "WM_SYSDEADCHAR" },
{264, "WM_KEYLAST" },
{265, "WM_UNICHAR" },
{265, "WM_WNT_CONVERTREQUESTEX" },
{266, "WM_CONVERTREQUEST" },
{267, "WM_CONVERTRESULT" },
{268, "WM_INTERIM" },
{269, "WM_IME_STARTCOMPOSITION" },
{270, "WM_IME_ENDCOMPOSITION" },
{271, "WM_IME_COMPOSITION" },
{271, "WM_IME_KEYLAST" },
{272, "WM_INITDIALOG" },
{273, "WM_COMMAND" },
{274, "WM_SYSCOMMAND" },
{275, "WM_TIMER" },
{276, "WM_HSCROLL" },
{277, "WM_VSCROLL" },
{278, "WM_INITMENU" },
{279, "WM_INITMENUPOPUP" },
{280, "WM_SYSTIMER" },
{287, "WM_MENUSELECT" },
{288, "WM_MENUCHAR" },
{289, "WM_ENTERIDLE" },
{290, "WM_MENURBUTTONUP" },
{291, "WM_MENUDRAG" },
{292, "WM_MENUGETOBJECT" },
{293, "WM_UNINITMENUPOPUP" },
{294, "WM_MENUCOMMAND" },
{295, "WM_CHANGEUISTATE" },
{296, "WM_UPDATEUISTATE" },
{297, "WM_QUERYUISTATE" },
{306, "WM_CTLCOLORMSGBOX" },
{307, "WM_CTLCOLOREDIT" },
{308, "WM_CTLCOLORLISTBOX" },
{309, "WM_CTLCOLORBTN" },
{310, "WM_CTLCOLORDLG" },
{311, "WM_CTLCOLORSCROLLBAR" },
{312, "WM_CTLCOLORSTATIC" },
{512, "WM_MOUSEFIRST" },
{512, "WM_MOUSEMOVE" },
{513, "WM_LBUTTONDOWN" },
{514, "WM_LBUTTONUP" },
{515, "WM_LBUTTONDBLCLK" },
{516, "WM_RBUTTONDOWN" },
{517, "WM_RBUTTONUP" },
{518, "WM_RBUTTONDBLCLK" },
{519, "WM_MBUTTONDOWN" },
{520, "WM_MBUTTONUP" },
{521, "WM_MBUTTONDBLCLK" },
{521, "WM_MOUSELAST" },
{522, "WM_MOUSEWHEEL" },
{523, "WM_XBUTTONDOWN" },
{524, "WM_XBUTTONUP" },
{525, "WM_XBUTTONDBLCLK" },
{528, "WM_PARENTNOTIFY" },
{529, "WM_ENTERMENULOOP" },
{530, "WM_EXITMENULOOP" },
{531, "WM_NEXTMENU" },
{532, "WM_SIZING" },
{533, "WM_CAPTURECHANGED" },
{534, "WM_MOVING" },
{536, "WM_POWERBROADCAST" },
{537, "WM_DEVICECHANGE" },
{544, "WM_MDICREATE" },
{545, "WM_MDIDESTROY" },
{546, "WM_MDIACTIVATE" },
{547, "WM_MDIRESTORE" },
{548, "WM_MDINEXT" },
{549, "WM_MDIMAXIMIZE" },
{550, "WM_MDITILE" },
{551, "WM_MDICASCADE" },
{552, "WM_MDIICONARRANGE" },
{553, "WM_MDIGETACTIVE" },
{560, "WM_MDISETMENU" },
{561, "WM_ENTERSIZEMOVE" },
{562, "WM_EXITSIZEMOVE" },
{563, "WM_DROPFILES" },
{564, "WM_MDIREFRESHMENU" },
{640, "WM_IME_REPORT" },
{641, "WM_IME_SETCONTEXT" },
{642, "WM_IME_NOTIFY" },
{643, "WM_IME_CONTROL" },
{644, "WM_IME_COMPOSITIONFULL" },
{645, "WM_IME_SELECT" },
{646, "WM_IME_CHAR" },
{648, "WM_IME_REQUEST" },
{656, "WM_IMEKEYDOWN" },
{656, "WM_IME_KEYDOWN" },
{657, "WM_IMEKEYUP" },
{657, "WM_IME_KEYUP" },
{672, "WM_NCMOUSEHOVER" },
{673, "WM_MOUSEHOVER" },
{674, "WM_NCMOUSELEAVE" },
{675, "WM_MOUSELEAVE" },
{768, "WM_CUT" },
{769, "WM_COPY" },
{770, "WM_PASTE" },
{771, "WM_CLEAR" },
{772, "WM_UNDO" },
{773, "WM_RENDERFORMAT" },
{774, "WM_RENDERALLFORMATS" },
{775, "WM_DESTROYCLIPBOARD" },
{776, "WM_DRAWCLIPBOARD" },
{777, "WM_PAINTCLIPBOARD" },
{778, "WM_VSCROLLCLIPBOARD" },
{779, "WM_SIZECLIPBOARD" },
{780, "WM_ASKCBFORMATNAME" },
{781, "WM_CHANGECBCHAIN" },
{782, "WM_HSCROLLCLIPBOARD" },
{783, "WM_QUERYNEWPALETTE" },
{784, "WM_PALETTEISCHANGING" },
{785, "WM_PALETTECHANGED" },
{786, "WM_HOTKEY" },
{791, "WM_PRINT" },
{792, "WM_PRINTCLIENT" },
{793, "WM_APPCOMMAND" },
{856, "WM_HANDHELDFIRST" },
{863, "WM_HANDHELDLAST" },
{864, "WM_AFXFIRST" },
{895, "WM_AFXLAST" },
{896, "WM_PENWINFIRST" },
{897, "WM_RCRESULT" },
{898, "WM_HOOKRCRESULT" },
{899, "WM_GLOBALRCCHANGE" },
{899, "WM_PENMISCINFO" },
{900, "WM_SKB" },
{901, "WM_HEDITCTL" },
{901, "WM_PENCTL" },
{902, "WM_PENMISC" },
{903, "WM_CTLINIT" },
{904, "WM_PENEVENT" },
{911, "WM_PENWINLAST" },
};

int k = 0;
string s;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId = LOWORD(wParam);

	if (k < 50) {
		s += "wParam =[" + to_string(wmId) + "],\r\n";
		k++;
	}

	if (flow_control && commands.count(wmId) == 1) {
		auto search = commands.find(wmId);
		string  s_msg = "wParam =[" + to_string(wmId)+ "], " + search->second + "\r\n";
		char *c_msg = new char[s_msg.length() + 1];
		strcpy(c_msg, s_msg.c_str());

		SendMessageA(box_out, EM_REPLACESEL, 0, (LPARAM) c_msg);
	}

	switch (message) {
	case WM_CREATE:
	{
		cntrl = CreateWindowEx(NULL,
			L"BUTTON", L"Cntrl",
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			10, 10, 290, 30,
			hWnd, (HMENU)BTN_CNTRL, GetModuleHandle(NULL), NULL);

		firstcmds = CreateWindowEx(NULL,
			L"BUTTON", L"First",
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			300, 10, 100, 30,
			hWnd, (HMENU)BTN_FIRST, GetModuleHandle(NULL), NULL);

		box_out = CreateWindowEx(NULL,
			L"Edit", NULL,
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_MULTILINE | WS_EX_RTLREADING | WS_EX_STATICEDGE | ES_AUTOHSCROLL | WS_VSCROLL | WS_EX_RTLREADING | WS_EX_LEFTSCROLLBAR,
			10, 50, 400, 500,
			hWnd, (HMENU)TEXTBOX, GetModuleHandle(NULL), NULL);
			
		break;
	}
	case WM_COMMAND:
	{
		if (wmId == BTN_CNTRL) {
			flow_control = !flow_control;
			if (flow_control) {
				SendMessageA(box_out, WM_SETTEXT, 0, (LPARAM) "");
				SendMessageA(box_out, EM_REPLACESEL, 0, (LPARAM) "Запустить диспетчеризацию!\r\n");
			}
			else if (!flow_control)
				SendMessageA(box_out, EM_REPLACESEL, 0, (LPARAM) "Остановить диспетчеризацию!\r\n");

			break;
		}
		
		if (wmId == BTN_FIRST) {
			flow_control = false;
			char *c_msg = new char[s.length() + 1];
			strcpy(c_msg, s.c_str());
			SendMessageA(box_out, WM_SETTEXT, 0, (LPARAM) c_msg);
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

HINSTANCE hInst;                     // текущий экземпляр
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

	if (!hWnd) 
		return FALSE;
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