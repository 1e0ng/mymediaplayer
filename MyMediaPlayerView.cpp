// MyMediaPlayerView.cpp : implementation of the CMyMediaPlayerView class
//
#include "stdafx.h"
#include "MyMediaPlayer.h"

#include "MyMediaPlayerDoc.h"
#include "MyMediaPlayerView.h"
#include "wmpplayer4.h"
#include "wmpcontrols.h"
#include "wmpsettings.h"
#define HIMETRIC_INCH 2540


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyMediaPlayerView

IMPLEMENT_DYNCREATE(CMyMediaPlayerView, CView)

BEGIN_MESSAGE_MAP(CMyMediaPlayerView, CView)
	//{{AFX_MSG_MAP(CMyMediaPlayerView)
	ON_WM_CREATE()
	ON_COMMAND(ID_OPER_OPENV, OnOperOpenv)
	ON_COMMAND(ID_OPER_PLAYV, OnOperPlayv)
	ON_COMMAND(ID_OPER_STOPV, OnOperStopv)
	ON_COMMAND(ID_OPER_STOPA, OnOperStopa)
	ON_COMMAND(ID_OPER_PLAYA, OnOperPlaya)
	ON_COMMAND(ID_OPER_OPENA, OnOperOpena)
	ON_WM_SIZE()
	ON_COMMAND(ID_OPER_OPEN, OnOperOpen)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyMediaPlayerView construction/destruction

CMyMediaPlayerView::CMyMediaPlayerView()
{
	// TODO: add construction code here

	m_Video=new CWMPPlayer4;
	m_Music=new CWMPPlayer4;
	m_pPicture = NULL;
	displayType=0;
}

CMyMediaPlayerView::~CMyMediaPlayerView()
{
	delete m_Video;
	delete m_Music;
	if (m_pPicture)
		m_pPicture->Release();
}

BOOL CMyMediaPlayerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyMediaPlayerView drawing

void CMyMediaPlayerView::OnDraw(CDC* pDC)
{
	CMyMediaPlayerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if(1==displayType&&m_pPicture){
		long hmWidth;
		long hmHeight;
		m_pPicture->get_Width(&hmWidth);
		m_pPicture->get_Height(&hmHeight);
		
		// convert himetric to pixels
		int nWidth= MulDiv(hmWidth, GetDeviceCaps(pDC->GetSafeHdc(),
		LOGPIXELSX), HIMETRIC_INCH);
		int nHeight= MulDiv(hmHeight, GetDeviceCaps(pDC->GetSafeHdc(),
		LOGPIXELSY), HIMETRIC_INCH);
		CRect rc;
		GetClientRect(&rc);
		
		// display picture using IPicture::Render
		m_pPicture->Render(pDC->GetSafeHdc(),(rc.Width()-nWidth)/2,(rc.Height()-nHeight)/2,
		nWidth,nHeight,0,hmHeight,hmWidth,-hmHeight,&rc);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMyMediaPlayerView printing

BOOL CMyMediaPlayerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyMediaPlayerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyMediaPlayerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyMediaPlayerView diagnostics

#ifdef _DEBUG
void CMyMediaPlayerView::AssertValid() const
{
	CView::AssertValid();
}

void CMyMediaPlayerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyMediaPlayerDoc* CMyMediaPlayerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyMediaPlayerDoc)));
	return (CMyMediaPlayerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyMediaPlayerView message handlers

int CMyMediaPlayerView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	HCURSOR hCursor=::LoadCursor(NULL, IDC_ARROW); 
	m_Video->Create(AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS|
	CS_PARENTDC, hCursor, 0, 0),
	NULL, WS_VISIBLE|WS_CHILD, CRect(0,0,0,0), this, 0);
	//m_Video->GetSettings().SetMute(TRUE);
	m_Video->SetStretchToFit(TRUE);
	m_Music->Create(AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS|
	CS_PARENTDC, hCursor, 0, 0),
	NULL, WS_VISIBLE|WS_CHILD, CRect(0,0,0,0), this, 0);
	//m_Music->ShowWindow(SW_HIDE);
	
	return 0;
}

void CMyMediaPlayerView::OnOperOpenv() 
{
	static char BASED_CODE szFilter[] =	"Video Files (*.avi;*.mpg;*.mpeg)|*.avi;*.mpg;*.mpeg|";
	CFileDialog fileDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, szFilter);
	if(fileDlg.DoModal() == IDOK)
		m_strVideo = fileDlg.GetPathName();	
}

void CMyMediaPlayerView::OnOperPlayv() 
{
	m_Video->GetControls().stop(); 
	m_Video->GetSettings().SetAutoStart(TRUE); 
	m_Video->SetUrl(m_strVideo);	
}

void CMyMediaPlayerView::OnOperStopv() 
{
	m_Video->GetControls().stop();	
}

void CMyMediaPlayerView::OnOperStopa() 
{
	m_Music->GetControls().stop();	
}

void CMyMediaPlayerView::OnOperPlaya() 
{
	m_Music->GetControls().stop(); 
	m_Music->GetSettings().SetAutoStart(TRUE); 
	m_Music->SetUrl(m_strMusic);
}

void CMyMediaPlayerView::OnOperOpena() 
{

	static char BASED_CODE szFilter[] = "Audio Files (*.wav;*.mp3)|*.wav;*.mp3||";
	CFileDialog fileDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, szFilter);
	if(fileDlg.DoModal() == IDOK)
		m_strMusic = fileDlg.GetPathName();
}

void CMyMediaPlayerView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	if(displayType==3){
		CRect rect;
		GetClientRect(rect);
		m_Video->MoveWindow(rect);
	}
	else if(displayType==2){
		CRect rect;
		GetClientRect(rect);
		m_Music->MoveWindow(rect);
	}
}

void CMyMediaPlayerView::OnOperOpen() 
{
}
void CMyMediaPlayerView::LoadPicture(CString strFile)
{
	HANDLE hFile=CreateFile(strFile,GENERIC_READ,0,NULL,OPEN_EXISTING,0,NULL);
	_ASSERTE(INVALID_HANDLE_VALUE != hFile);
	DWORD dwFileSize = GetFileSize(hFile, NULL);
	_ASSERTE(-1 != dwFileSize);
	LPVOID pvData = NULL;
	HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, dwFileSize);
	_ASSERTE(NULL != hGlobal);
	pvData = GlobalLock(hGlobal); 
	_ASSERTE(NULL != pvData);
	DWORD dwBytesRead = 0;
	BOOL bRead = ReadFile(hFile, pvData, dwFileSize, &dwBytesRead, NULL); 
	_ASSERTE(FALSE != bRead);
	GlobalUnlock(hGlobal);
	CloseHandle(hFile);
	LPSTREAM pstm = NULL;
	HRESULT hr = CreateStreamOnHGlobal(hGlobal, TRUE, &pstm); 
	_ASSERTE(SUCCEEDED(hr) && pstm);
	if (m_pPicture) 
	m_pPicture->Release();
	hr = ::OleLoadPicture(pstm, dwFileSize, FALSE, IID_IPicture, (LPVOID *)&m_pPicture);
	_ASSERTE(SUCCEEDED(hr) && m_pPicture);
	pstm->Release(); 
	Invalidate();
}

void CMyMediaPlayerView::OnFileOpen() 
{
	static char BASED_CODE szFilter[] =	"All Files(*.bmp;*.gif;*.jpg;*.ico;*.emf;*.wmf;*.wav;*.mp3;*.midi;*.avi;*.mpg;*.mpeg;*.wmv;*.rm;*.rmvb)|*.bmp;*.gif;*.jpg;*.ico;*.emf;*.wmf;*.wav;*.mp3;*.midi;*.avi;*.mpg;*.mpeg;*.wmv;*.rm;*.rmvb|Image Files(*.bmp;*.gif;*.jpg;*.ico;*.emf;*.wmf)|*.bmp;*.gif;*.jpg;*.ico;*.emf;*.wmf|Audio Files(*.wav;*.mp3;*.midi)|*.wav;*.mp3;*.midi|Video Files(*.avi;*.mpg;*.mpeg;*.wmv;*.rm;*.rmvb)|*.avi;*.mpg;*.mpeg;*.wmv;*.rm;*.rmvb||";
	CFileDialog fileDlg(TRUE, NULL, "testdata\\image021.jpg", OFN_HIDEREADONLY, szFilter);
	if(fileDlg.DoModal() == IDOK){
		CString strfilename=fileDlg.GetPathName();
		CString strfileext=fileDlg.GetFileExt();
		if(strfileext=="bmp"||strfileext=="gif"||strfileext=="jpg"||strfileext=="ico"||strfileext=="emf"||strfileext=="wmf"){
			displayType=1;
			m_Video->GetControls().stop();
			m_Video->ShowWindow(SW_HIDE);
			m_Music->ShowWindow(SW_HIDE);
			LoadPicture(strfilename);
		}
		else if(strfileext=="wav"||strfileext=="mp3"||strfileext=="midi"){
			displayType=2;
			m_Video->GetControls().stop();
			m_Video->ShowWindow(SW_HIDE);
			m_Music->ShowWindow(SW_SHOW);
			CRect rect;
			GetClientRect(rect);
			m_Music->MoveWindow(rect);
			m_strMusic=strfilename;
			m_Music->GetControls().stop(); 
			m_Music->GetSettings().SetAutoStart(TRUE); 
			m_Music->SetUrl(m_strMusic);
		}
		else if(strfileext=="avi"||strfileext=="mpg"||strfileext=="mpeg"||strfileext=="wmv"||strfileext=="rm"||strfileext=="rmvb"){
			displayType=3;
			m_Music->ShowWindow(SW_HIDE);
			m_Video->ShowWindow(SW_SHOW);
			CRect rect;
			GetClientRect(rect);
			m_Video->MoveWindow(rect);
			m_strVideo=strfilename;
			m_Video->GetControls().stop(); 
			m_Music->GetControls().stop(); 
			m_Video->GetSettings().SetAutoStart(TRUE); 
			m_Video->SetUrl(m_strVideo);	
		}
	}
}
