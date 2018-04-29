// CRemote.cpp: 구현 파일
//

#include "stdafx.h"
#include "Remote Server.h"
#include "CRemote.h"
#include "afxdialogex.h"


// CRemote 대화 상자

IMPLEMENT_DYNAMIC(CRemote, CDialog)

CRemote::CRemote(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_REMOTE, pParent)
{

}

CRemote::~CRemote()
{
}

void CRemote::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRemote, CDialog)
END_MESSAGE_MAP()


// CRemote 메시지 처리기




BOOL CRemote::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 첫 번째 인자 >> 인터넷 방식 설정
	// 두 번째 인자 >> SOCK_STREAM -> tcp 방식 SOCK_DGRAM -> udp 방식
	// 세 번째 인자 >> 프로토콜 명을 적는데 0을 적을 경우 알아서 프로토콜을 매칭 시켜준다.
	mh_listen_socket = (AF_INET, SOCK_STREAM, 0); 

	struct sockaddr_in srv_addr;
	srv_addr.sin_family = AF_INET;
	srv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	srv_addr.sin_port = htons(20001);

	bind(mh_listen_socket, (SOCKADDR *)&srv_addr, sizeof(srv_addr));
	
	listen(mh_listen_socket, 1);

	WSAAsyncSelect(mh_listen_socket, m_hWnd, 27001, FD_ACCEPT); // 비동기 방식
	// FD_ACCEPT란 클라이언트가 지금 서버쪽으로 접속하려는 이벤트
	// 다시 설명을 하면 소켓이 서버쪽으로 접속하려게 감지되면 m_hWnd윈도우에게 27001번을 달라고하는 것이다.


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


LRESULT CRemote::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	if (27001 == message)
	{

	}

	return CDialog::WindowProc(message, wParam, lParam);
}
