// MyMediaPlayerView.h : interface of the CMyMediaPlayerView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYMEDIAPLAYERVIEW_H__8271FA12_11E7_4DC5_9335_5C24D66DE1FA__INCLUDED_)
#define AFX_MYMEDIAPLAYERVIEW_H__8271FA12_11E7_4DC5_9335_5C24D66DE1FA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CWMPPlayer4;
class CMyMediaPlayerView : public CView
{
protected: // create from serialization only
	CMyMediaPlayerView();
	DECLARE_DYNCREATE(CMyMediaPlayerView)


// Attributes
public:
	CMyMediaPlayerDoc* GetDocument();
protected:
	CWMPPlayer4 *m_Video;
	CWMPPlayer4 *m_Music;
	CString m_strVideo;
	CString m_strMusic;
	LPPICTURE m_pPicture;
	int displayType;
private: 
	void LoadPicture(CString strFile);
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyMediaPlayerView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyMediaPlayerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyMediaPlayerView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnOperOpenv();
	afx_msg void OnOperPlayv();
	afx_msg void OnOperStopv();
	afx_msg void OnOperStopa();
	afx_msg void OnOperPlaya();
	afx_msg void OnOperOpena();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnOperOpen();
	afx_msg void OnFileOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MyMediaPlayerView.cpp
inline CMyMediaPlayerDoc* CMyMediaPlayerView::GetDocument()
   { return (CMyMediaPlayerDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYMEDIAPLAYERVIEW_H__8271FA12_11E7_4DC5_9335_5C24D66DE1FA__INCLUDED_)
