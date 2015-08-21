
// TechSmithWebBrowserDlg.h : header file
//

#pragma once
#include "RedirectWebBrowser.h"

// CTechSmithWebBrowserDlg dialog
class CTechSmithWebBrowserDlg : public CDialogEx
{
   // Construction
public:
   CTechSmithWebBrowserDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
   enum { IDD = IDD_TECHSMITHWEBBROWSER_DIALOG };
#endif

protected:
   virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
   HICON m_hIcon;

   RedirectWebBrowser m_Browser;
   BOOL m_bMobile;

   // Generated message map functions
   virtual BOOL OnInitDialog();
   afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
   afx_msg void OnPaint();
   afx_msg HCURSOR OnQueryDragIcon();
   afx_msg void OnSize(UINT nType, int cx, int cy);
   DECLARE_MESSAGE_MAP()
public:
   afx_msg void OnBnClickedBtnBack();
   afx_msg void OnBnClickedBtnForward();
   afx_msg void OnBnClickedBtnGo();
   afx_msg void OnBnClickedBtnMobile();
};
