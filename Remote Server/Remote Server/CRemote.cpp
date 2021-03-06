// CRemote.cpp: 구현 파일
//

#include "stdafx.h"
#include "Remote Server.h"
#include "CRemote.h"
#include "afxdialogex.h"


// CRemote 대화 상자

IMPLEMENT_DYNAMIC(CRemote, CDialog)

// CRemote 클래스 생성자
CRemote::CRemote(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_REMOTE, pParent)
{
	m_client_count = 0;
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

/*
	wParam >> 이 메시지가 발생하게된 소켓 핸들이 들어 있음. (mh_listen_socket 소켓이라고 보면 됨)
			  그런데 mh_listen_socket 소켓이랑 같다고 mh_listen_socket 소켓을 사용하는 것보다 
			  wParam을 사용하는 습관을 들이는게 더 좋다.

	lParam >> 에러가 있는지 그리고 어떤 이벤트 때문에 발생했는지에 대한 정보가 들어 있음.
*/
LRESULT CRemote::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	if (27001 == message) // 27001 메시지가 들어올 때 이 조건문을 실행함.
	{
		if (MAX_CLIENT_COUNT > m_client_count)
		{

			SOCKET h_socket = (SOCKET)wParam;  // mh_listen_socket 핸들값과 동일

			struct sockaddr_in client_addr;
			int sockaddr_in_size = sizeof(client_addr);

			mh_client_list[m_client_count] = accept(h_socket, (SOCKADDR *)&client_addr, &sockaddr_in_size);
			m_client_count++;


			// 접속한 사용자의 주소를 알고 싶을 경우
			CString ip_address;
			ip_address = inet_ntoa(client_addr.sin_addr);
			MessageBox(ip_address, L"conneted new client", MB_OK);
		}
		else
		{

		}
	}
	return CDialog::WindowProc(message, wParam, lParam);
}
