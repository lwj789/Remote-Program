
// ChildView.cpp: CChildView 클래스의 구현
//

#include "stdafx.h"
#include "Remote Server.h"
#include "ChildView.h"
#include "CRemote.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_REMOTE_START, &CChildView::OnRemoteStart)
	ON_UPDATE_COMMAND_UI(ID_REMOTE_START, &CChildView::OnUpdateRemoteStart)
	ON_COMMAND(ID_SAMPLE, &CChildView::OnSample)
	ON_UPDATE_COMMAND_UI(ID_SAMPLE, &CChildView::OnUpdateSample)
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnRemoteStart()
{
	//AfxMessageBox(L"Remote Start");

	// 항목 확인란 체크 표시.
	m_nDrawMdoe = REMOTE_START_MODE;

	// Remote 다이얼로그 창 띄움
	CRemote dlg;
	dlg.DoModal();
}


void CChildView::OnUpdateRemoteStart(CCmdUI *pCmdUI)
{
	// Remote Start 모드이면 메뉴에 체크 표시
	pCmdUI->SetCheck(m_nDrawMdoe == REMOTE_START_MODE ? 1 : 0);
}




void CChildView::OnSample()
{
	AfxMessageBox(L"sample menu");
	m_nDrawMdoe = SAMPLE_MODE;
}


void CChildView::OnUpdateSample(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(m_nDrawMdoe == SAMPLE_MODE ? 1 : 0);
}
