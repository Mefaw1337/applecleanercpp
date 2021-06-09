#include "includes.h"
//_CRT_SECURE_NO_WARNINGS




int CloseGame()
{
	system(_xor_("taskkill /f /im EpicGamesLauncher.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im FortniteClient-Win64-Shipping.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im OneDrive.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im RustClient.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im Origin.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im r5apex.exe >nul 2>&1").c_str());
	return(1);
}


void AllocConsoleLoader()
{
	AllocConsole(); freopen("CONIN$", "r", stdin); freopen("CONOUT$", "w", stderr); freopen("CONOUT$", "w", stdout);
	HWND hwnd = GetConsoleWindow(); MoveWindow(hwnd, 0, 0, 0, 0, false);
}




void Start()
{
	POINT OldCursorPos;
	GetCursorPos(&OldCursorPos);
	;
	INPUT    Input = { 0 };
	::ZeroMemory(&Input, sizeof(INPUT));
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	::SendInput(1, &Input, sizeof(INPUT));
	BlockInput(true);
	SetCursorPos(0, 0);
	::ZeroMemory(&Input, sizeof(INPUT));
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	::SendInput(1, &Input, sizeof(INPUT));
	SetCursorPos(0, 0);
	SetCursorPos(OldCursorPos.x, OldCursorPos.y);
	BlockInput(false);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwMode = 0;
	GetConsoleMode(hOut, &dwMode);
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(hOut, dwMode);
	HWND handle = GetConsoleWindow();
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, new_size);
	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_EX_RIGHTSCROLLBAR & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX & ~WS_MINIMIZEBOX);
	HANDLE hInput;
	DWORD prev_mode;
	hInput = GetStdHandle(STD_INPUT_HANDLE);
	

	
}

int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	
	
	
	Start();
	CloseGame();


	system(_xor_("color 70").c_str()); //reminds old apple cleaner colors

	

	print::set_warning(_xor_("[*] Allocating console").c_str());
	Sleep(4000);
	static bool consolecreated = false;
	if (!consolecreated) { AllocConsoleLoader(); consolecreated = true; }
	
	LPCTSTR lpzClass = CLEANERNAME;
	if (!RegMyWindowClass(hInstance, lpzClass))
		return 1;
	RECT screen_rect;
	GetWindowRect(GetDesktopWindow(), &screen_rect);
	int x = screen_rect.right / 2 - 150;
	int y = screen_rect.bottom / 2 - 75;
	HWND hWnd = CreateWindow(lpzClass, CLEANERNAME, WS_POPUP, x, y, WINDOW_WIDTH, WINDOW_HEIGHT, NULL, NULL, hInstance, NULL);
	if (!hWnd) return 2;
	LPDIRECT3D9 pD3D;
	if ((pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL) {
		UnregisterClass(lpzClass, hInstance);
	}

	ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
	g_d3dpp.Windowed = TRUE;
	g_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	g_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	g_d3dpp.EnableAutoDepthStencil = TRUE;
	g_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;
	if (pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice) < 0) {
		pD3D->Release();
		UnregisterClass(lpzClass, hInstance);
		return 0;
	}

	ImGui_ImplDX9_Init(hWnd, g_pd3dDevice);

	
	
	Apple::ImGuiRender::ApplyAppleStyle(); //apply apple imgui colors
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			continue;
		}

		ImGui_ImplDX9_NewFrame();
		
		DWORD dwFlag = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse;
		static bool open = true;
		if (!open) ExitProcess(0);

		
		ImGui::Begin(CLEANERNAME, &open, ImVec2(WINDOW_WIDTH, WINDOW_HEIGHT), 1.0f, dwFlag); {
			ImGui::PushItemWidth(-1.0f);

			if (ImGui::Button(_xor_("Launch Apple Cleaner [BETA]").c_str(), ImVec2(ImGui::GetWindowSize().x * 0.90f, 0.0f)))
			{
				Apple::CleanBeta();
			}

			if (ImGui::Button(_xor_("Launch Apple Cleaner").c_str(), ImVec2(ImGui::GetWindowSize().x * 0.90f, 0.0f)))
			{
				Apple::CleanNormal();
			}

			if (ImGui::Button(_xor_("Launch Apple Cleaner [OLD]").c_str(), ImVec2(ImGui::GetWindowSize().x * 0.90f, 0.0f)))
			{
				Apple::CleanOld();
			}

		}
		ImGui::End();

		g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, false);
		g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
		g_pd3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
		if (g_pd3dDevice->BeginScene() >= 0)
		{
			ImGui::Render();
			g_pd3dDevice->EndScene();
		}
		g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
	}
	ImGui_ImplDX9_Shutdown();
	if (g_pd3dDevice) g_pd3dDevice->Release();
	if (pD3D) pD3D->Release();
	UnregisterClass(CLEANERNAME, hInstance);
	return 0;
}