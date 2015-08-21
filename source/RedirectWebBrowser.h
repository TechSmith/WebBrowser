#pragma once

#include "CWebBrowser2.h"
class CRedirectHandler : public IDocHostUIHandler
{
   int m_nCount;
   BOOL m_bHostNavigates;

public:
   CRedirectHandler(BOOL bHostNavigates);

   HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void __RPC_FAR *__RPC_FAR *ppvObject);

   ULONG STDMETHODCALLTYPE AddRef(void);
   ULONG STDMETHODCALLTYPE Release(void);

   HRESULT STDMETHODCALLTYPE GetHostInfo(DOCHOSTUIINFO * pInfo);

   HRESULT STDMETHODCALLTYPE ShowUI(DWORD, IOleInPlaceActiveObject*, IOleCommandTarget*,
      IOleInPlaceFrame*, IOleInPlaceUIWindow*) {
      return E_NOTIMPL;
   }
   HRESULT STDMETHODCALLTYPE HideUI(void) { return S_OK; }
   HRESULT STDMETHODCALLTYPE UpdateUI(void) { return S_OK; }

   HRESULT STDMETHODCALLTYPE EnableModeless(BOOL) { return E_NOTIMPL; }
   HRESULT STDMETHODCALLTYPE OnDocWindowActivate(BOOL) { return E_NOTIMPL; }
   HRESULT STDMETHODCALLTYPE OnFrameWindowActivate(BOOL) { return E_NOTIMPL; }
   HRESULT STDMETHODCALLTYPE ResizeBorder(LPCRECT, IOleInPlaceUIWindow *, BOOL) { return E_NOTIMPL; }

   //we want to ignore right click events so return S_OK
   HRESULT STDMETHODCALLTYPE ShowContextMenu(DWORD, POINT *, IUnknown *, IDispatch *) { return S_OK; }

   HRESULT STDMETHODCALLTYPE TranslateAccelerator(LPMSG pMsg, const GUID *, DWORD) { return E_NOTIMPL; }
   HRESULT STDMETHODCALLTYPE GetOptionKeyPath(LPOLESTR *, DWORD) { return E_NOTIMPL; }
   HRESULT STDMETHODCALLTYPE GetDropTarget(IDropTarget *, IDropTarget **);
   HRESULT STDMETHODCALLTYPE GetExternal(IDispatch ** p);
   HRESULT STDMETHODCALLTYPE TranslateUrl(DWORD dwTranslate, OLECHAR * strURLIn, OLECHAR ** ppstrURLOut);
   HRESULT STDMETHODCALLTYPE FilterDataObject(IDataObject *, IDataObject **);
};

class RedirectWebBrowser : public CWebBrowser2
{
public:
   RedirectWebBrowser(BOOL bHostNavigates);

   void HookRedirectHandler();

protected:
   CRedirectHandler m_RedirectHandler;
};

