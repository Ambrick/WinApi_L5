#define WIN32_LEAN_AND_MEAN             // Исключите редко используемые компоненты из заголовков Windows
// Файлы заголовков Windows
#include <windows.h>

// Файлы заголовков среды выполнения C
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// установите здесь ссылки на дополнительные заголовки, требующиеся для программы
#include <math.h>
#include <locale.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;


#define IDR_MAINFRAME			128
#define IDD_DISPDIALOG			102
#define IDI_DISPDIALOG			107
#define IDI_SMALL				108
#define IDC_DISPDIALOG			109
#define IDC_MYICON				2
#define IDS_APP_TITLE			103

#ifndef IDC_STATIC
#define IDC_STATIC				-1
#endif


#define ID_BTN_PUSH  02
#define ID_TEXTBOX   01

#define MAX_LOADSTRING 100

