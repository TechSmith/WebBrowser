#include "stdafx.h"
#include "RedirectWebBrowser.h"

//////////////////////////////////////////////////////////////////////////
// CRedirectHandler

CRedirectHandler::CRedirectHandler(BOOL bHostNavigates)
   : m_nCount(0), m_bHostNavigates(bHostNavigates)
{
}

HRESULT STDMETHODCALLTYPE CRedirectHandler::QueryInterface(REFIID riid, void __RPC_FAR *__RPC_FAR *ppvObject)
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

ULONG STDMETHODCALLTYPE CRedirectHandler::AddRef(void)
{
   m_nCount++;
   return S_OK;
}

ULONG STDMETHODCALLTYPE CRedirectHandler::Release(void)
{
   m_nCount--;
   return S_OK;
}

HRESULT STDMETHODCALLTYPE CRedirectHandler::GetHostInfo(DOCHOSTUIINFO * pInfo)
{
   pInfo->dwFlags = DOCHOSTUIFLAG_NO3DBORDER;
   pInfo->dwDoubleClick = DOCHOSTUIDBLCLK_DEFAULT;

   // This is the whole reason we have a custom DocHostUIHandler.
   // This flag causes 302 redirects to fire the Navigating event.
   pInfo->dwFlags |= DOCHOSTUIFLAG_ENABLE_REDIRECT_NOTIFICATION;

   // This flag makes navigating work when having a form post where the link goes to the same page
   // (e.g javascript:void(0)); however it messes with getting a BeforeNavigate2 event :(
   if (m_bHostNavigates)
      pInfo->dwFlags |= DOCHOSTUIFLAG_HOST_NAVIGATES;

   return S_OK;
}

HRESULT STDMETHODCALLTYPE CRedirectHandler::GetExternal(IDispatch ** p)
{
   if (QueryInterface(IID_IDispatch, (void**)p) != S_OK)
      return S_FALSE;

   return S_OK;
}

HRESULT STDMETHODCALLTYPE CRedirectHandler::TranslateUrl(DWORD dwTranslate, OLECHAR * strURLIn, OLECHAR ** ppstrURLOut)
{
   //ppstrURLOut = NULL;
   return S_FALSE;
}

HRESULT STDMETHODCALLTYPE CRedirectHandler::GetDropTarget(IDropTarget * pDropTarget, IDropTarget ** ppDropTarget)
{
   //ppDropTarget = NULL;
   return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE CRedirectHandler::FilterDataObject(IDataObject * pDO, IDataObject ** ppDORet)
{
   //ppDORet = NULL;
   return S_FALSE;
}

RedirectWebBrowser::RedirectWebBrowser(BOOL bHostNavigates)
   : m_RedirectHandler(bHostNavigates)
{
}

void RedirectWebBrowser::HookRedirectHandler()
{
   __super::put_Silent(TRUE);//Disables script errors.

   __super::SetUIHandler(&m_RedirectHandler);
}

