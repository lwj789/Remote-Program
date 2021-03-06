
// ChildView.h: CChildView 클래스의 인터페이스
//


#pragma once

// menu bar 체크 상태 표시 모양
enum DRAW_MODE{REMOTE_START_MODE, SAMPLE_MODE};

// CChildView 창

class CChildView : public CWnd
{
// 생성입니다.
public:
	CChildView();

// 특성입니다.
public:
	// menu bar 체크 상태 표시 모양
	int m_nDrawMdoe;
	int m_nHatchStyle;

// 작업입니다.
public:

// 재정의입니다.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 구현입니다.
public:
	virtual ~CChildView();

	// 생성된 메시지 맵 함수
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRemoteStart();
	afx_msg void OnUpdateRemoteStart(CCmdUI *pCmdUI);
	afx_msg void OnSample();
	afx_msg void OnUpdateSample(CCmdUI *pCmdUI);
};

