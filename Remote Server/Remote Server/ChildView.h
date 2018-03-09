
// ChildView.h: CChildView 클래스의 인터페이스
//


#pragma once


// CChildView 창

class CChildView : public CWnd
{
private:
	// listen 소켓을 이용해 클라이언트 접속을 받아주는 기능을 구현함.
	SOCKET mh_listen_socket;

// 생성입니다.
public:
	CChildView();

// 특성입니다.
public:

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
};

