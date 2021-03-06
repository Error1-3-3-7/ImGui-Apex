// Dear ImGui: standalone example application for DirectX 9
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

#include "imgui.h"
#include "imgui_impl_dx9.h"
#include "imgui_impl_win32.h"
#include <d3d9.h>
#include <tchar.h>
#include <ctime>
#include <iostream>
#include <vector>


// Data
static LPDIRECT3D9              g_pD3D = NULL;
static LPDIRECT3DDEVICE9        g_pd3dDevice = NULL;
static D3DPRESENT_PARAMETERS    g_d3dpp = {};

// Forward declarations of helper functions
bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void ResetDevice();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


void Colors() {
    ImGuiStyle& style = ImGui::GetStyle();
    style.WindowMinSize = ImVec2(440, 400);
    style.Colors[ImGuiCol_WindowBg] = ImColor(16, 16, 16);
    style.Colors[ImGuiCol_ChildBg] = ImColor(25, 25, 25);
    style.Colors[ImGuiCol_Text] = ImColor(255, 255, 255);
    style.Colors[ImGuiCol_CheckMark] = ImColor(255, 255, 255);
    
}

// Main code
int main(int, char**)
{
    // Create application window
    //ImGui_ImplWin32_EnableDpiAwareness();
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, _T("Error.#1234"), NULL };
    ::RegisterClassEx(&wc);
    HWND hwnd = ::CreateWindow(wc.lpszClassName, _T("Error.#1234"), WS_OVERLAPPEDWINDOW, 100, 100, 1280, 800, NULL, NULL, wc.hInstance, NULL);

    // Initialize Direct3D
    if (!CreateDeviceD3D(hwnd))
    {
        CleanupDeviceD3D();
        ::UnregisterClass(wc.lpszClassName, wc.hInstance);
        return 1;
    }


    ::ShowWindow(hwnd, SW_SHOWDEFAULT);
    ::UpdateWindow(hwnd);


    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    Colors();
    

    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplDX9_Init(g_pd3dDevice);


    bool show_demo_window = true;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    // Main loop
    bool done = false;

    while (!done)
    {
        // Poll and handle messages (inputs, window resize, etc.)
        // See the WndProc() function below for our to dispatch events to the Win32 backend.
        MSG msg;
        while (::PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            if (msg.message == WM_QUIT)
                done = true;
        }
        if (done)
            break;

        // Start the Dear ImGui frame
        ImGui_ImplDX9_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();


        bool tabb = 0;

       // MENU OPTIONS
        bool EnableAim;
        bool ShowFOV;
        bool IgnoreKnocked;
        bool VisibleOnly;
        bool NoSpread;
        bool Prediction;
        bool head;
        bool chest;
        bool stomach;

        // Visuals
        bool EnableVis;
        bool Box;
        bool headdot;
        bool chams;
        bool healthbar;
        bool shieldbar;
        bool shownames;
        bool showdistance;

       // items
        bool enableitems;
        bool Ammo;
        bool Scopes;
        bool attachments;
        bool weapons;
        bool Medical;
        bool Throwables;
        bool wearables;


        bool MemoryAim;








       // MENU OPTIONS


        {
          
                
            

            static float f = 0.0f;
            static int counter = 0;
            static int tabb = 0;
            
            static float slidefloat = 0.f;
            static float slidefloat1 = 0.f;
            static float slidefloat2 = 0.f;
            static float slidefloat3 = 0.f;
            static float SliderInt = 0;

            

            
            
            ImGui::Begin("Error.#1234", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiTableFlags_Hideable);

            static bool Checkbox = true;

            if (ImGui::Button("Aimbot", ImVec2(100, 20)))
            {
                tabb = 0;
            }
            ImGui::SameLine();
            if (ImGui::Button("Visuals", ImVec2(100, 20)))
            {
                tabb = 1;
            }
            ImGui::SameLine();
            if (ImGui::Button("Misc", ImVec2(100, 20)))
            {
                tabb = 2;
            }
            ImGui::SameLine();
            if (ImGui::Button("Settings", ImVec2(100, 20)))
            {
                tabb = 3;
            }
             
            ImGui::BeginChild("FW");
            {

                static bool Checkbox = true;
                ImGui_ImplDX9_NewFrame();

                // AIMBOT >>

                if (tabb == 0)
                {
                    // Aimbot Tab
                    ImGui::Text("____Aimbot__________________________________________________________________");
                    ImGui::Text(" ");
                    ImGui::Checkbox("Enabled", &EnableAim);
                    ImGui::Text(" ");
                    ImGui::Checkbox("Show FOV", &ShowFOV);
                    ImGui::Checkbox("Ignore Knocked", &IgnoreKnocked);
                    ImGui::Checkbox("Visible Only", &VisibleOnly);
                    ImGui::Checkbox("No-Spread", &NoSpread);
                    ImGui::Checkbox("Prediction", &Prediction);
                    ImGui::Checkbox("Head", &head);
                    ImGui::SameLine();
                    ImGui::Checkbox("Chest", &chest);
                    ImGui::SameLine();
                    ImGui::Checkbox("Stomach", &stomach);
                    ImGui::SliderFloat("FOV", &slidefloat, 0.f, 360.f);
                    ImGui::SliderFloat("Smooth", &slidefloat1, 0.f, 10.f);
                    ImGui::Text("______________________________________________________________________");
                    ImGui::Text("Recommendation, Use smoothness.");
                    // Aimbot Tab
                }

                // VISUALS >>

                else if (tabb == 1)
                {
                    // Visual Tab

                    // Players
                    ImGui::Text("_______Players_______________________________Items______________________");
                    ImGui::Text(" ");
                    ImGui::Checkbox("Enabled", &EnableVis);

                    //items Enabled
                    ImGui::SameLine();
                    ImGui::Text("                           ");
                    ImGui::SameLine();
                    ImGui::Checkbox("Enabled", &enableitems);
                    // items Enabled

                    ImGui::Text(" ");
                    ImGui::Checkbox("Box", &Box);

                    // Items Ammo

                    ImGui::SameLine();
                    ImGui::Text("                               ");
                    ImGui::SameLine();
                    ImGui::Checkbox("Ammo", &Ammo);

                    // Items Ammo

                    ImGui::Checkbox("Head Dot", &headdot);

                    // Items Scopes

                    ImGui::SameLine();
                    ImGui::Text("                          ");
                    ImGui::SameLine();
                    ImGui::Checkbox("Scopes", &Scopes);

                    // Items Scopes

                    ImGui::Checkbox("Chams", &chams);

                    // Items Attachments

                    ImGui::SameLine();
                    ImGui::Text("                             ");
                    ImGui::SameLine();
                    ImGui::Checkbox("Attachments", &attachments);

                    // Items Attachments


                    ImGui::Checkbox("Health Bar", &healthbar);

                    // Items Weapons

                    ImGui::SameLine();
                    ImGui::Text("                        ");
                    ImGui::SameLine();
                    ImGui::Checkbox("Weapons", &weapons);

                    // Items Weapons

                    ImGui::Checkbox("Shield Bar", &shieldbar);

                    // Items Medical

                    ImGui::SameLine();
                    ImGui::Text("                        ");
                    ImGui::SameLine();
                    ImGui::Checkbox("Medical", &Medical);

                    // Items Medical

                    ImGui::Checkbox("Show Names", &shownames);

                    // Items Throwables

                    ImGui::SameLine();
                    ImGui::Text("                        ");
                    ImGui::SameLine();
                    ImGui::Checkbox("Throwables", &Throwables);

                    // Items Throwables

                    ImGui::Checkbox("Show Distance", &showdistance);

                    // Items Wearables

                    ImGui::SameLine();
                    ImGui::Text("                     ");
                    ImGui::SameLine();
                    ImGui::Checkbox("Wearables", &wearables);

                    // Items Wearables







                    
                    

                    // Visual Tab
                }

                else if (tabb == 2)
                {
                    //Misc Tab
                    ImGui::Text("____Misc__________________________________________________________________");
                    ImGui::Text(" ");
                    ImGui::Text("MADE BY Error.#1234");


                    //Misc Tab
                }

                else if (tabb == 3)
                {
                    // Settings tab

                    ImGui::Text("____Options__________________________________________________________________");
                    ImGui::Text(" ");
                    ImGui::Text("MADE BY Error.#1234");

                    // Settings tab
                }

            }

           

         

            







            ImGui::EndChild();
           
            ImGui::End();
        }


        ImGui::EndFrame();
        g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
        g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
        g_pd3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, FALSE);
        D3DCOLOR clear_col_dx = D3DCOLOR_RGBA((int)(clear_color.x*clear_color.w*255.0f), (int)(clear_color.y*clear_color.w*255.0f), (int)(clear_color.z*clear_color.w*255.0f), (int)(clear_color.w*255.0f));
        g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, clear_col_dx, 1.0f, 0);
        if (g_pd3dDevice->BeginScene() >= 0)
        {
            ImGui::Render();
            ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
            g_pd3dDevice->EndScene();
        }
        HRESULT result = g_pd3dDevice->Present(NULL, NULL, NULL, NULL);

        // Handle loss of D3D9 device
        if (result == D3DERR_DEVICELOST && g_pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
            ResetDevice();
    }

    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    ::DestroyWindow(hwnd);
    ::UnregisterClass(wc.lpszClassName, wc.hInstance);

    return 0;
}

// Helper functions

bool CreateDeviceD3D(HWND hWnd)
{
    if ((g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
        return false;

    // Create the D3DDevice
    ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
    g_d3dpp.Windowed = TRUE;
    g_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    g_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN; // Need to use an explicit format with alpha if needing per-pixel alpha composition.
    g_d3dpp.EnableAutoDepthStencil = TRUE;
    g_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
    g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;           // Present with vsync
    //g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;   // Present without vsync, maximum unthrottled framerate
    if (g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice) < 0)
        return false;

    return true;
}

void CleanupDeviceD3D()
{
    if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = NULL; }
    if (g_pD3D) { g_pD3D->Release(); g_pD3D = NULL; }
}

void ResetDevice()
{
    ImGui_ImplDX9_InvalidateDeviceObjects();
    HRESULT hr = g_pd3dDevice->Reset(&g_d3dpp);
    if (hr == D3DERR_INVALIDCALL)
        IM_ASSERT(0);
    ImGui_ImplDX9_CreateDeviceObjects();
}

// Forward declare message handler from imgui_impl_win32.cpp
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Win32 message handler
// You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
// - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
// - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
// Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            g_d3dpp.BackBufferWidth = LOWORD(lParam);
            g_d3dpp.BackBufferHeight = HIWORD(lParam);
            ResetDevice();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        ExitProcess(0);
        ::PostQuitMessage(0);
        return 0;
    }
    return ::DefWindowProc(hWnd, msg, wParam, lParam);
}
