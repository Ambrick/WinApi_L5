#define IDS_APP_TITLE			103

#define IDR_MAINFRAME			128
#define IDD_PROJECT4_DIALOG	102

#define IDM_EXIT				105
#define IDI_PROJECT4			107
#define IDI_SMALL				108
#define IDC_PROJECT4			109
#define IDC_MYICON				2
#ifndef IDC_STATIC
#define IDC_STATIC				-1
#endif
// Следующие стандартные значения для новых объектов
//
#ifdef APSTUDIO_INVOKED
#ifndef APSTUDIO_READONLY_SYMBOLS

#define _APS_NO_MFC					130
#define _APS_NEXT_RESOURCE_VALUE	129
#define _APS_NEXT_COMMAND_VALUE		32771
#define _APS_NEXT_CONTROL_VALUE		1000
#define _APS_NEXT_SYMED_VALUE		110
#endif
#endif


#define BTN_PUSH  02
#define TEXTBOX   01

#define MAX_LOADSTRING 100

bool flow_control = true;
HWND box_out, btn;

unordered_map < int, string > commands = {
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

