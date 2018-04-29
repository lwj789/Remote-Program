#pragma once


// CRemote 대화 상자

class CRemote : public CDialog
{
	DECLARE_DYNAMIC(CRemote)

public:
	CRemote(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CRemote();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_REMOTE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()


private:
	// listen 소켓을 이용해 클라이언트 접속을 받아주는 기능을 구현함.
	SOCKET mh_listen_socket;

public:
	virtual BOOL OnInitDialog();
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
};
