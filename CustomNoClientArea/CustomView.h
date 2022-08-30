#pragma once

#include <DuiLib/UIlib.h>
#include "BaseWindow.h"
class CustomView final : public BaseWindow
{
    UILIB_RESOURCETYPE GetResourceType() const override;

protected:
    LPCTSTR GetWindowClassName() const override;
    CDuiString GetSkinFile() override;
    CDuiString GetSkinFolder() override;
};