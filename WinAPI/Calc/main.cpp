#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<cstdio>
#include"resource.h"
#include"resource1.h"

CONST CHAR g_sz_MY_WINDOW_CLASS[] = "My Calculator";
CONST CHAR g_sz_DEFAULT_SKIN[] = "square_blue";
//g_  - Global
//sz_ - String Zero
CONST INT g_i_START_X = 10;
CONST INT g_i_START_Y = 10;

CONST INT g_i_INTERVAL = 5;

CONST INT g_i_BTN_SIZE = 64;
CONST INT g_i_BTN_SIZE_WITH_INTERVAL = g_i_BTN_SIZE + g_i_INTERVAL;
CONST INT g_i_BTN_SIZE_DOUBLE = g_i_BTN_SIZE * 2 + g_i_INTERVAL;

CONST INT g_i_DISPLAY_WIDTH = g_i_BTN_SIZE * 5 + g_i_INTERVAL * 4;
CONST INT g_i_DISPLAY_HEIGHT = 50;

CONST INT g_i_BTN_START_X = g_i_START_X;
CONST INT g_i_BTN_START_Y = g_i_START_Y + g_i_DISPLAY_HEIGHT + g_i_INTERVAL;

CONST INT g_i_WINDOW_WIDTH = g_i_DISPLAY_WIDTH + g_i_START_X * 2 + 16;
CONST INT g_i_WINDOW_HEIGHT = g_i_DISPLAY_HEIGHT + g_i_START_Y * 3 + g_i_BTN_SIZE_WITH_INTERVAL * 4 + 30;

CONST CHAR g_OPERATIONS[] = "+-*/";

CONST CHAR g_sz_DISPLAY_FONT[] = "Tahoma";
CONST INT g_i_DISPLAY_FONT_HEIGHT = g_i_DISPLAY_HEIGHT - 2;
CONST INT g_i_DISPLAY_FONT_WIDTH = g_i_DISPLAY_FONT_HEIGHT / 2.5;

CONST COLORREF g_cr_SQUARE_BLUE = RGB(1, 96, 160);
CONST COLORREF g_cr_ROUND_BLUE = RGB(41, 143, 209);

CONST HBRUSH hBrushSquareBlue = CreateSolidBrush(g_cr_SQUARE_BLUE);
CONST HBRUSH hBrushRoundBlue = CreateSolidBrush(g_cr_ROUND_BLUE);

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
VOID SetSkin(HWND hwnd, CONST CHAR sz_skin[]);
VOID FormatAndDisplayMessage(HWND hwnd, DWORD dwErrorMessageID);
VOID SetWindowBackground(HWND hwnd, COLORREF crBackground);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	//1) ����������� ������ ����:
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(wc));

	wc.cbSize = sizeof(wc);
	wc.cbWndExtra = 0;
	wc.cbClsExtra = 0;
	wc.style = 0;

	wc.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(hInstance, IDI_APPLICATION);
	wc.hCursor = LoadCursor(hInstance, IDC_ARROW);
	//wc.hbrBackground = CreateSolidBrush(RGB(1, 96, 160));
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;

	wc.hInstance = hInstance;
	wc.lpszMenuName = NULL;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = g_sz_MY_WINDOW_CLASS;

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Class registration failed", "Error", MB_OK | MB_ICONERROR);
		return 0;
	}

	//2) �������� ����:
	HWND hwnd = CreateWindowEx
	(
		NULL,
		g_sz_MY_WINDOW_CLASS,
		g_sz_MY_WINDOW_CLASS,
		WS_SYSMENU | WS_MINIMIZEBOX,
		CW_USEDEFAULT, CW_USEDEFAULT,
		g_i_WINDOW_WIDTH, g_i_WINDOW_HEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	if (hwnd == NULL)
	{
		MessageBox(NULL, "Window creation failed", "Error", MB_OK | MB_ICONERROR);
		return 0;
	}
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	//3) ������ ����� ���������:
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static DOUBLE a = 0;
	static DOUBLE b = 0;
	static INT operation = 0;
	static BOOL input = FALSE;
	static BOOL operation_input = false;

	static COLORREF crBackground = RGB(0, 0, 240);
	static HBRUSH hBrush = CreateSolidBrush(crBackground);
	static CHAR sz_skin[FILENAME_MAX] = {};

	switch (uMsg)
	{
	case WM_CREATE:
	{
		HWND hDisplay = CreateWindowEx
		(
			NULL, "Static", "0",
			WS_CHILD | WS_VISIBLE | SS_RIGHT | SS_SUNKEN | SS_CENTERIMAGE,
			g_i_START_X, g_i_START_Y,
			g_i_DISPLAY_WIDTH, g_i_DISPLAY_HEIGHT,
			hwnd,
			(HMENU)IDC_STATIC,
			GetModuleHandle(NULL),
			NULL
		);
		//SendMessage(hDisplay, WM_SETTEXT, 0, (LPARAM)"Display");
		/*LOGFONT lFont;
		ZeroMemory(&lFont, sizeof(lFont));
		lFont.lfHeight = 32;
		lFont.lfWidth = 12;
		lFont.lfEscapement = 0;
		lFont.lfOrientation = 0;
		lFont.lfWeight = FW_DEMIBOLD;
		lFont.lfItalic = FALSE;
		lFont.lfUnderline = FALSE;
		lFont.lfStrikeOut = FALSE;
		lFont.lfCharSet = DEFAULT_CHARSET;
		lFont.lfOutPrecision = OUT_TT_PRECIS;
		lFont.lfClipPrecision = CLIP_DEFAULT_PRECIS;
		lFont.lfQuality = ANTIALIASED_QUALITY;
		lFont.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
		strcpy(lFont.lfFaceName,"Arial");

		HFONT hFont = CreateFontIndirect(&lFont);*/
		HFONT hFont = CreateFont
		(
			g_i_DISPLAY_FONT_HEIGHT, g_i_DISPLAY_FONT_WIDTH,
			GM_ADVANCED, 0, FW_DEMIBOLD,
			FALSE, FALSE, FALSE,
			DEFAULT_CHARSET,
			OUT_CHARACTER_PRECIS,
			CLIP_CHARACTER_PRECIS,
			ANTIALIASED_QUALITY,
			DEFAULT_PITCH | FF_DONTCARE,
			g_sz_DISPLAY_FONT
		);
		SendMessage(hDisplay, WM_SETFONT, (WPARAM)hFont, TRUE);

		INT i_digit = 1;
		CHAR sz_digit[2] = {};
		/*for (int i = 3; i > 0; i--)
		{
			for (int j = 0; j < 3; j++)
			{
				sz_digit[0] = i_digit + (char)48;
				CreateWindowEx
				(
					NULL, "Button", sz_digit,
					WS_CHILDWINDOW | WS_VISIBLE | BS_PUSHBUTTON,
					g_i_START_X + g_i_BTN_SIZE_WITH_INTERVAL * j,
					g_i_START_Y + g_i_BTN_SIZE_WITH_INTERVAL * i,
					g_i_BTN_SIZE, g_i_BTN_SIZE,
					hwnd,
					(HMENU)(IDC_BUTTON_0 + i_digit),
					GetModuleHandle(NULL),
					NULL
				);
				i_digit++;
			}
		}*/
		for (int i = 2; i >= 0; i--)
		{
			for (int j = 0; j < 3; j++)
			{
				sz_digit[0] = i_digit + (char)48;
				CreateWindowEx
				(
					NULL, "Button", sz_digit,
					WS_CHILDWINDOW | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP,
					g_i_BTN_START_X + g_i_BTN_SIZE_WITH_INTERVAL * j,
					g_i_BTN_START_Y + g_i_BTN_SIZE_WITH_INTERVAL * i,
					g_i_BTN_SIZE, g_i_BTN_SIZE,
					hwnd,
					(HMENU)(IDC_BUTTON_0 + i_digit),
					GetModuleHandle(NULL),
					NULL
				);
				i_digit++;
			}
		}

		//////////////////////////////////////////////////////////////////////////////////////////////
		CreateWindowEx
		(
			NULL, "Button", "0",
			WS_CHILDWINDOW | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP,
			g_i_BTN_START_X, g_i_BTN_START_Y + g_i_BTN_SIZE_WITH_INTERVAL * 3,
			g_i_BTN_SIZE_DOUBLE, g_i_BTN_SIZE,
			hwnd,
			(HMENU)IDC_BUTTON_0,
			GetModuleHandle(NULL),
			NULL
		);
		strcpy(sz_skin, g_sz_DEFAULT_SKIN);
		SetSkin(hwnd, g_sz_DEFAULT_SKIN);
		CreateWindowEx
		(
			NULL, "Button", ".",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			g_i_BTN_START_X + g_i_BTN_SIZE_WITH_INTERVAL * 2, g_i_BTN_START_Y + g_i_BTN_SIZE_WITH_INTERVAL * 3,
			g_i_BTN_SIZE, g_i_BTN_SIZE,
			hwnd,
			(HMENU)IDC_BUTTON_POINT,
			GetModuleHandle(NULL),
			NULL
		);
		//////////////////////////////////////////////////////////////////////////////////////////////
		INT i_operation = 0;
		CHAR sz_operation[2] = {};
		for (int i = 3; i >= 0; i--)
		{
			sz_operation[0] = g_OPERATIONS[i];
			CreateWindowEx
			(
				NULL, "Button", sz_operation,
				WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
				g_i_BTN_START_X + g_i_BTN_SIZE_WITH_INTERVAL * 3, g_i_BTN_START_Y + g_i_BTN_SIZE_WITH_INTERVAL * (3 - i),
				g_i_BTN_SIZE, g_i_BTN_SIZE,
				hwnd,
				(HMENU)(IDC_BUTTON_PLUS + i),
				GetModuleHandle(NULL),
				NULL
			);
		}
		//HWND hBtnPlus = GetDlgItem(hwnd, IDC_BUTTON_PLUS);
		//HBITMAP hBitMap = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP_PLUS));
		//SendMessage(hBtnPlus, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBitMap);
		CreateWindowEx
		(
			NULL, "Button", "<-",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			g_i_BTN_START_X + g_i_BTN_SIZE_WITH_INTERVAL * 4, g_i_BTN_START_Y,
			g_i_BTN_SIZE, g_i_BTN_SIZE,
			hwnd,
			(HMENU)IDC_BUTTON_BSP,
			GetModuleHandle(NULL),
			NULL
		);
		CreateWindowEx
		(
			NULL, "Button", "C",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			g_i_BTN_START_X + g_i_BTN_SIZE_WITH_INTERVAL * 4, g_i_BTN_START_Y + g_i_BTN_SIZE_WITH_INTERVAL,
			g_i_BTN_SIZE, g_i_BTN_SIZE,
			hwnd,
			(HMENU)IDC_BUTTON_CLEAR,
			GetModuleHandle(NULL),
			NULL
		);
		CreateWindowEx
		(
			NULL, "Button", "=",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			g_i_BTN_START_X + g_i_BTN_SIZE_WITH_INTERVAL * 4, g_i_BTN_START_Y + g_i_BTN_SIZE_WITH_INTERVAL * 2,
			g_i_BTN_SIZE, g_i_BTN_SIZE_DOUBLE,
			hwnd,
			(HMENU)IDC_BUTTON_EQUAL,
			GetModuleHandle(NULL),
			NULL
		);
	}
	break;
	//case WM_ERASEBKGND:
	case WM_PRINT:
	case WM_PAINT:
	{
		//HDC hdc = GetDC(hwnd);
		HBRUSH hBackground = CreateSolidBrush(crBackground);
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		//ZeroMemory(&ps, sizeof(ps));
		//ps.hdc = hdc;
		//ps.fErase = TRUE;
		//GetClientRect(hwnd, &ps.rcPaint);
		//SelectObject(hdc, hBackground);
		FillRect(ps.hdc, &ps.rcPaint, hBackground);
		//FillRect(hdc, &ps.rcPaint, hBrush);
		FormatAndDisplayMessage(hwnd, GetLastError());
		
		//DeleteObject(hBackground);
		//ReleaseDC(hwnd, hdc);
		EndPaint(hwnd, &ps);
	}
	break;
	case WM_CTLCOLORSTATIC:
	{
		if ((HWND)lParam == GetDlgItem(hwnd, IDC_STATIC))
		{
			HDC hdc = (HDC)wParam;
			//SetBkMode(hdc, OPAQUE);
			SetDCBrushColor(hdc, RGB(0, 0, 100));
			SetBkColor(hdc, RGB(0, 0, 100));
			//SetBkColor(hdc, RGB(240, 240, 240));
			SetTextColor(hdc, RGB(255, 0, 0));
			return (int)GetStockObject(DC_BRUSH);
		}
	}
	break;
	/*case WM_CTLCOLOREDIT:
	{
		HDC hdc = (HDC)wParam;
		SetBkMode(hdc, OPAQUE);
		SetBkColor(hdc, RGB(0, 0, 100)); HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 255));
		SetTextColor(hdc, RGB(255, 0, 0));
		return (LRESULT)hBrush;
	}
	break;*/
	case WM_COMMAND:
	{
		CONST INT SIZE = 256;
		CHAR sz_buffer[SIZE] = {};
		HWND hStatic = GetDlgItem(hwnd, IDC_STATIC);
		SendMessage(hStatic, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
		if (LOWORD(wParam) >= IDC_BUTTON_0 && LOWORD(wParam) <= IDC_BUTTON_9 || LOWORD(wParam) == IDC_BUTTON_POINT)
		{
			DOUBLE d_buffer = atof(sz_buffer);
			if (d_buffer == a)
			{
				SendMessage(hStatic, WM_SETTEXT, 0, (LPARAM)"");
				sz_buffer[0] = 0;
			}

			CHAR sz_symbol[2] = {};
			sz_symbol[0] = CHAR(LOWORD(wParam) - IDC_BUTTON_0 + '0');
			if (LOWORD(wParam) == IDC_BUTTON_POINT)
			{
				if (strchr(sz_buffer, '.'))break;
				sz_symbol[0] = '.';
			}
			strcat(sz_buffer, sz_symbol);
			//if (sz_buffer[0] == '0' && strchr(sz_buffer, '.') == 0)memmove(&sz_buffer[0], &sz_buffer[1], strlen(sz_buffer)-1);
			SendMessage(hStatic, WM_SETTEXT, 0, (LPARAM)sz_buffer);
			input = TRUE;
		}
		if (LOWORD(wParam) == IDC_BUTTON_CLEAR)
		{
			SendMessage(hStatic, WM_SETTEXT, 0, (LPARAM)"");
			a = b = operation = 0;
			input = FALSE;
			operation_input = FALSE;
		}
		if (LOWORD(wParam) == IDC_BUTTON_BSP)
		{
			if (strcmp(sz_buffer, "0") == 0 || strlen(sz_buffer) == 0)break;
			sz_buffer[strlen(sz_buffer) - 1] = 0;
			SendMessage(hStatic, WM_SETTEXT, 0, (LPARAM)sz_buffer);
		}
		if (LOWORD(wParam) >= IDC_BUTTON_PLUS && LOWORD(wParam) <= IDC_BUTTON_SLASH)
		{
			SendMessage(hStatic, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
			if (input)
			{
				b = atof(sz_buffer);
				input = FALSE;
			}
			if (a == 0)a = b;
			SendMessage(hwnd, WM_COMMAND, IDC_BUTTON_EQUAL, 0);
			operation = LOWORD(wParam);
			/*switch (LOWORD(wParam))
			{
			case IDC_BUTTON_PLUS:	operation = '+';		break;
			case IDC_BUTTON_MINUS:	operation = '-';		break;
			case IDC_BUTTON_ASTER:	operation = '*';		break;
			case IDC_BUTTON_SLASH:	operation = '/';		break;
			}*/
			operation_input = TRUE;
		}
		if (LOWORD(wParam) == IDC_BUTTON_EQUAL)
		{
			if (input)
			{
				SendMessage(hStatic, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
				b = atof(sz_buffer);
				input = FALSE;
			}
			/*switch (operation)
			{
			case '+':	a += b;		break;
			case '-':	a -= b;		break;
			case '*':	a *= b;		break;
			case '/':	a /= b;		break;
			}*/
			switch (operation)
			{
			case IDC_BUTTON_PLUS:	a += b;		break;
			case IDC_BUTTON_MINUS:	a -= b;		break;
			case IDC_BUTTON_ASTER:	a *= b;		break;
			case IDC_BUTTON_SLASH:	a /= b;		break;
			}
			operation_input = FALSE;
			sprintf(sz_buffer, "%F", a);
			SendMessage(hStatic, WM_SETTEXT, 0, (LPARAM)sz_buffer);
		}
	}
	break;
	case WM_KEYDOWN:
	{
		if (GetKeyState(VK_SHIFT) < 0)
		{
			if (wParam == 0x38)SendMessage(hwnd, WM_COMMAND, IDC_BUTTON_ASTER, 0);
		}
		else if (LOWORD(wParam) >= 0x30 && LOWORD(wParam) <= 0x39)	//Digits:0123....9
		{
			SendMessage(hwnd, WM_COMMAND, wParam - 0x30 + 1000, 0);
		}
		if (LOWORD(wParam) >= 0x60 && LOWORD(wParam) <= 69)
			SendMessage(hwnd, WM_COMMAND, wParam - 0x60 + 1000, 0);

		switch (LOWORD(wParam))
		{
		case VK_OEM_PERIOD:	SendMessage(hwnd, WM_COMMAND, IDC_BUTTON_POINT, 0);	break;
		case VK_OEM_PLUS:	SendMessage(hwnd, WM_COMMAND, IDC_BUTTON_PLUS, 0);	break;
		case VK_OEM_MINUS:	SendMessage(hwnd, WM_COMMAND, IDC_BUTTON_MINUS, 0);	break;
		case VK_MULTIPLY:	SendMessage(hwnd, WM_COMMAND, IDC_BUTTON_ASTER, 0);	break;
		case VK_OEM_2:
		case VK_DIVIDE:		SendMessage(hwnd, WM_COMMAND, IDC_BUTTON_SLASH, 0);	break;
		case VK_BACK:		SendMessage(hwnd, WM_COMMAND, IDC_BUTTON_BSP, 0); break;
		case VK_RETURN:		SendMessage(hwnd, WM_COMMAND, IDC_BUTTON_EQUAL, 0); break;
		case VK_ESCAPE:		SendMessage(hwnd, WM_COMMAND, IDC_BUTTON_CLEAR, 0); break;
		}
	}
	break;
	case WM_CONTEXTMENU:
	{
		HMENU hMenu = CreatePopupMenu();
		InsertMenu(hMenu, 0, MF_BYPOSITION | MF_STRING, IDC_EXIT, "Exit");
		InsertMenu(hMenu, 0, MF_BYPOSITION | MF_SEPARATOR, 0, NULL);
		InsertMenu(hMenu, 0, MF_BYPOSITION | MF_STRING, IDC_SQUARE, "Square buttons");
		InsertMenu(hMenu, 0, MF_BYPOSITION | MF_STRING, IDC_ROUND, "Round buttons");

		switch (TrackPopupMenuEx(hMenu, TPM_BOTTOMALIGN | TPM_LEFTALIGN | TPM_RETURNCMD, LOWORD(lParam), HIWORD(lParam), hwnd, NULL))
		{
		//case IDC_ROUND:	SetSkin(hwnd, "round_blue");	break;
		//case IDC_SQUARE:SetSkin(hwnd, "square_blue");	break;
		case IDC_ROUND:	strcpy(sz_skin, "round_blue");	crBackground = g_cr_ROUND_BLUE;	break;
		case IDC_SQUARE:strcpy(sz_skin, "square_blue"); crBackground = g_cr_SQUARE_BLUE;break;
		case IDC_EXIT:	SendMessage(hwnd, IDC_EXIT, 0, 0);
		}
		SetSkin(hwnd, sz_skin);
		SetWindowBackground(hwnd, crBackground);
		//UpdateWindow(hwnd);
		//SendMessage(hwnd, WM_PRINT, 0, PRF_CLIENT | PRF_ERASEBKGND);
		/*BOOL update = UpdateWindow(hwnd);
		DWORD dwErrorMessageID = GetLastError();
		LPSTR lpMessageBuffer = NULL;
		DWORD sdwSize = FormatMessage
		(
			FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			dwErrorMessageID,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_RUSSIAN_RUSSIA),
			(LPSTR)&lpMessageBuffer,
			0,
			NULL
		);
		MessageBox(hwnd, lpMessageBuffer, "Error", MB_OK | MB_ICONERROR);*/
	}
	break;
	case WM_DESTROY:PostQuitMessage(0);		break;
	case IDC_EXIT:
	case WM_CLOSE:	DestroyWindow(hwnd);	break;
	default:		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return NULL;
}
VOID SetSkin(HWND hwnd, CONST CHAR sz_skin[])
{
	//	IDB_BUTTON_0	BITMAP			"ButtonsBPM\\square_blue\\button_0.bmp"
	CONST INT SIZE = 10;
	HWND hButton[SIZE] = {};
	//HBITMAP hBitmap[SIZE] = {};
	for (int i = 0; i < SIZE; i++)
	{
		hButton[i] = GetDlgItem(hwnd, i + IDC_BUTTON_0);
		//hBitmap[i] = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(i + IDB_BITMAP_0));
		//HBITMAP hBitmap = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(i + IDB_BITMAP_0));
		CHAR sz_filename[FILENAME_MAX] = {};
		sprintf(sz_filename, "ButtonsBPM\\%s\\button_%i.bmp", sz_skin, i);
		HBITMAP hBitmap = (HBITMAP)LoadImage
		(
			GetModuleHandle(NULL),
			sz_filename,
			IMAGE_BITMAP,
			i > 0 ? g_i_BTN_SIZE : g_i_BTN_SIZE_DOUBLE, g_i_BTN_SIZE,
			LR_LOADFROMFILE
		);
		/*DWORD dwErrorMessageID = GetLastError();
		LPSTR lpMessageBuffer = NULL;
		DWORD dwSize = FormatMessage
		(
			FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			dwErrorMessageID,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_RUSSIAN_RUSSIA),
			(LPSTR)&lpMessageBuffer,
			0,
			NULL
		);
		MessageBox(hwnd, lpMessageBuffer, "Error", MB_OK | MB_ICONERROR);*/
		SendMessage(hButton[i], BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBitmap);
	}
	//if (strcmp(sz_skin, "square_blue") == 0)	SetClassLongPtr(hwnd, GCLP_HBRBACKGROUND, (LONG_PTR)hBrushSquareBlue);
	//if (strcmp(sz_skin, "round_blue") == 0)		SetClassLongPtr(hwnd, GCLP_HBRBACKGROUND, (LONG_PTR)hBrushRoundBlue);
	HDC hdc = GetDC(hwnd);
	if (strcmp(sz_skin, "square_blue") == 0)	SetDCBrushColor(hdc, RGB(1, 96, 160));
	if (strcmp(sz_skin, "round_blue") == 0)		SetDCBrushColor(hdc, RGB(41, 143, 209));
	//UpdateWindow(hwnd);
	//SendMessage(hwnd, WM_PAINT, 0, 0);
	ReleaseDC(hwnd, hdc);
}
VOID FormatAndDisplayMessage(HWND hwnd, DWORD dwErrorMessageID)
{
	//DWORD dwErrorMessageID = GetLastError();
	LPSTR lpMessageBuffer = NULL;
	DWORD dwSize = FormatMessage
	(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		dwErrorMessageID,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_RUSSIAN_RUSSIA),
		(LPSTR)&lpMessageBuffer,
		0,
		NULL
	);
	MessageBox(hwnd, lpMessageBuffer, "Error", MB_OK | MB_ICONERROR);

}
VOID SetWindowBackground(HWND hwnd, COLORREF crBackground)
{
	HDC hdc = GetDC(hwnd);
	//SendMessage(hwnd, WM_ERASEBKGND, (WPARAM)hdc, 0);
	//PAINTSTRUCT ps;
	//BeginPaint(hwnd, &ps);
	//ZeroMemory(&ps, sizeof(ps));
	//ps.hdc = hdc;
	//ps.fErase = TRUE;
	RECT rect;
	GetClientRect(hwnd, &rect);
	HBRUSH hBackground = CreateSolidBrush(crBackground);
	//SelectObject(hdc, hBackground);
	FillRect(hdc, &rect, hBackground);
	//FillRect(hdc, &ps.rcPaint, hBrush);
	FormatAndDisplayMessage(hwnd, GetLastError());

	DeleteObject(hBackground);
	ReleaseDC(hwnd, hdc);
	//EndPaint(hwnd, &ps);
	UpdateWindow(hwnd);
}