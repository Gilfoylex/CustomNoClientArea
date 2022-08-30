#include <DuiLib/StdAfx.h>

#include "CustomView.h"

UILIB_RESOURCETYPE CustomView::GetResourceType() const
{
    return UILIB_RESOURCE;
}

LPCTSTR CustomView::GetWindowClassName() const
{
    return L"CustomView";
}

CDuiString CustomView::GetSkinFile()
{
    // CustomView.xml resource id is 200
    return L"200";
}

CDuiString CustomView::GetSkinFolder()
{
    return L"";
}
