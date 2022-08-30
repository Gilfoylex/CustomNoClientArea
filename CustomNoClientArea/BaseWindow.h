#pragma once

#include <DuiLib/UIlib.h>

using namespace DuiLib;
class BaseWindow : public WindowImplBase
{
public:
    BaseWindow() = default;
    ~BaseWindow() override = default;

    LRESULT HandleCustomMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) override;
    LRESULT OnNcCalcSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) override;
    LRESULT OnNcActivate(UINT, WPARAM wParam, LPARAM, BOOL& bHandled) override;
    LRESULT OnNcPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) override;
};