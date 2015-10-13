// MyMediaPlayerDoc.cpp : implementation of the CMyMediaPlayerDoc class
//

#include "stdafx.h"
#include "MyMediaPlayer.h"

#include "MyMediaPlayerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyMediaPlayerDoc

IMPLEMENT_DYNCREATE(CMyMediaPlayerDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyMediaPlayerDoc, CDocument)
	//{{AFX_MSG_MAP(CMyMediaPlayerDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyMediaPlayerDoc construction/destruction

CMyMediaPlayerDoc::CMyMediaPlayerDoc()
{
	// TODO: add one-time construction code here

}

CMyMediaPlayerDoc::~CMyMediaPlayerDoc()
{
}

BOOL CMyMediaPlayerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMyMediaPlayerDoc serialization

void CMyMediaPlayerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMyMediaPlayerDoc diagnostics

#ifdef _DEBUG
void CMyMediaPlayerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyMediaPlayerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyMediaPlayerDoc commands
