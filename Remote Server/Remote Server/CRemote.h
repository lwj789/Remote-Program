#pragma once


// CRemote 대화 상자

#define MAX_CLIENT_COUNT 10 // 클라이언트를 10명까지 관리하겠다는 의미로 사용

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
	SOCKET mh_listen_socket; // listen 소켓을 이용해 클라이언트 접속을 받아주는 기능을 구현함.

	SOCKET mh_client_list[MAX_CLIENT_COUNT];
	int m_client_count;  // 객체 생성자에서 이 변수를 0으로 초기화 한다는점 참고.

public:
	virtual BOOL OnInitDialog();
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
};
	