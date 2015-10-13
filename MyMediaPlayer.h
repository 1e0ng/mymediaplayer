// MyMediaPlayer.h : main header file for the MYMEDIAPLAYER application
//

#if !defined(AFX_MYMEDIAPLAYER_H__227A3C18_5DD5_4321_857B_4D61A1ABAB8D__INCLUDED_)
#define AFX_MYMEDIAPLAYER_H__227A3C18_5DD5_4321_857B_4D61A1ABAB8D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyMediaPlayerApp:
// See MyMediaPlayer.cpp for the implementation of this class
//

class CMyMediaPlayerApp : public CWinApp
{
public:
	CMyMediaPlayerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyMediaPlayerApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMyMediaPlayerApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYMEDIAPLAYER_H__227A3C18_5DD5_4321_857B_4D61A1ABAB8D__INCLUDED_)
