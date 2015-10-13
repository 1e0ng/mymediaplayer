// MyMediaPlayerDoc.h : interface of the CMyMediaPlayerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYMEDIAPLAYERDOC_H__5BFA21E9_1DA1_40AA_AAB1_107C7844B265__INCLUDED_)
#define AFX_MYMEDIAPLAYERDOC_H__5BFA21E9_1DA1_40AA_AAB1_107C7844B265__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyMediaPlayerDoc : public CDocument
{
protected: // create from serialization only
	CMyMediaPlayerDoc();
	DECLARE_DYNCREATE(CMyMediaPlayerDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyMediaPlayerDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyMediaPlayerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyMediaPlayerDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYMEDIAPLAYERDOC_H__5BFA21E9_1DA1_40AA_AAB1_107C7844B265__INCLUDED_)
