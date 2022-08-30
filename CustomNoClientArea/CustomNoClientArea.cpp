// CustomNoClientArea.cpp : Defines the entry point for the application.
//

#include <DuiLib/StdAfx.h>
#include <DuiLib/UIlib.h>
#include "CustomNoClientArea.h"
#include "CustomView.h"


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    DuiLib::CPaintManagerUI::SetInstance(hInstance);
    const auto hr = ::CoInitialize(nullptr);
    if (FAILED(hr)) return 0;
    auto view = new CustomView();

    auto hwnd = view->Create(nullptr, L"CustomView", (WS_VISIBLE | WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN), WS_EX_OVERLAPPEDWINDOW, 0, 0, 0, 0);
    view->CenterWindow();
    ::ShowWindow(view->GetHWND(), SW_SHOW);

    DuiLib::CPaintManagerUI::MessageLoop();

    ::CoUninitialize();

    return 0;
}
