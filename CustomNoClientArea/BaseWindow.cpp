#include <DuiLib/StdAfx.h>
#include <dwmapi.h>
#pragma comment(lib, "dwmapi.lib")
#include "BaseWindow.h"

LRESULT BaseWindow::HandleCustomMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
    if (uMsg == WM_DESTROY)
    {
        ::PostQuitMessage(0);
    }
    else if (uMsg == WM_ACTIVATE)
    {
        constexpr MARGINS margins {0,0,0,0};
        ::DwmExtendFrameIntoClientArea(GetHWND(), &margins);
        bHandled = false;
    }

    return 0;
}

LRESULT BaseWindow::OnNcCalcSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
    auto pRect = reinterpret_cast<LPRECT>(lParam);
    pRect->left += 4;
    pRect->right -= 4;
    pRect->bottom -= 4;

    if (wParam == TRUE)
    {
        return WVR_REDRAW;
    }

    bHandled = false;
    return 0;
}

LRESULT BaseWindow::OnNcActivate(UINT uint, WPARAM wParam, LPARAM long_ptr, BOOL& bHandled)
{
    //::RedrawWindow(GetHWND(), nullptr, nullptr, RDW_UPDATENOW);
    //return 0;
    return ::DefWindowProcW(GetHWND(), WM_NCACTIVATE, wParam, -1);
}

LRESULT BaseWindow::OnNcPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
    bHandled = false;
    return 0;
}
