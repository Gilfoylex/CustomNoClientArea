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
        constexpr MARGINS margins {1,1,1,1};
        ::DwmExtendFrameIntoClientArea(GetHWND(), &margins);
        bHandled = false;
    }

    return 0;
}

LRESULT BaseWindow::OnNcCalcSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
    if (wParam == TRUE)
    {
        return WVR_REDRAW;
    }

    bHandled = false;
    return 0;
}

LRESULT BaseWindow::OnNcActivate(UINT uint, WPARAM wParam, LPARAM long_ptr, BOOL& bHandled)
{
    ::RedrawWindow(GetHWND(), nullptr, nullptr, RDW_UPDATENOW);
    return 0;
}

LRESULT BaseWindow::OnNcPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
    bHandled = false;
    return 0;
}
