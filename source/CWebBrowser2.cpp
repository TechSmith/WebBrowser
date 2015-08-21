// CWebBrowser2.cpp  : Definition of ActiveX Control wrapper class(es) created by Microsoft Visual C++


#include "stdafx.h"
#include "CWebBrowser2.h"

//////////////////////////////////////////////////////////////////////////
// CUIHandler

CUIHandler::CUIHandler()
{
   m_nCount = 0;
}

HRESULT STDMETHODCALLTYPE CUIHandler::TranslateAccelerator(LPMSG pMsg, const GUID *, DWORD)
{
   if (pMsg)
   {
      if ((pMsg->message == WM_KEYDOWN) || (pMsg->message == WM_KEYUP))
      {
         if ((pMsg->wParam == VK_TAB) ||
             (pMsg->wParam == VK_F4) ||
             (pMsg->wParam == VK_ESCAPE) ||
             (pMsg->wParam == VK_LEFT) ||
             (pMsg->wParam == VK_SPACE) ||
             (pMsg->wParam == VK_RETURN) ||
             (pMsg->wParam == VK_SHIFT) ||
             (pMsg->wParam == VK_UP) ||
             (pMsg->wParam == VK_DOWN) ||
             (pMsg->wParam == VK_RIGHT) ||
             (pMsg->wParam == VK_MENU) ||
             (pMsg->wParam == VK_CONTROL))
         {
            return E_NOTIMPL;
         }
         else
         {
            return S_OK;
         }
      }
   }

   return E_NOTIMPL;
}


HRESULT STDMETHODCALLTYPE CUIHandler::QueryInterface(REFIID riid, void __RPC_FAR *__RPC_FAR *ppvObject)
{
   if ((riid == IID_IDocHostUIHandler) || (riid == IID_IDispatch))
   {
      *ppvObject = this;
      return S_OK;
   }
   else
   {
      return E_NOINTERFACE;
   }
};

ULONG STDMETHODCALLTYPE CUIHandler::AddRef(void)
{
   m_nCount++;
   return S_OK;
}

ULONG STDMETHODCALLTYPE CUIHandler::Release(void)
{
   m_nCount--;
   return S_OK;
}

HRESULT STDMETHODCALLTYPE CUIHandler::GetHostInfo(DOCHOSTUIINFO * pInfo)
{
   pInfo->dwFlags = DOCHOSTUIFLAG_NO3DBORDER;
   pInfo->dwDoubleClick = DOCHOSTUIDBLCLK_DEFAULT;
   return S_OK;
}

HRESULT STDMETHODCALLTYPE CUIHandler::GetExternal(IDispatch ** p)
{
   if (QueryInterface(IID_IDispatch, (void**)p) != S_OK)
      return S_FALSE;

   return S_OK;
}


/////////////////////////////////////////////////////////////////////////////
// CWebBrowser2

IMPLEMENT_DYNCREATE(CWebBrowser2, CWnd)

// CWebBrowser2 properties

// CWebBrowser2 operations
