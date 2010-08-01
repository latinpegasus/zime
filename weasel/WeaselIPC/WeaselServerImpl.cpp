#include "stdafx.h"
#include "WeaselIPCImpl.h"

WeaselServer::Impl::Impl()
: m_handler(0)
{
}

WeaselServer::Impl::~Impl()
{
}

BOOL WeaselServer::Impl::PreTranslateMessage(MSG* pMsg)
{
	return PreTranslateMessage(pMsg);
}

BOOL WeaselServer::Impl::OnIdle()
{
	return FALSE;
}

LRESULT WeaselServer::Impl::OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	// clients connects to server via calls to FindWindow() with SERVER_WND_NAME
	::SetWindowText( m_hWnd,  SERVER_WND_NAME ); 

	// notify clients that we are ready serving
	HANDLE hEvent = OpenEvent( EVENT_ALL_ACCESS, FALSE,  SERVER_EVENT_NAME );
	if( hEvent != INVALID_HANDLE_VALUE )
	{
		SetEvent(hEvent);
		CloseHandle(hEvent);
	}

	return 0;
}

LRESULT WeaselServer::Impl::OnClose(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	StopServer();
	return 0;
}

LRESULT WeaselServer::Impl::OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled)
{
	// TODO: clean up engines

	bHandled = FALSE;
	return 1;
}

int WeaselServer::Impl::StartServer()
{
	// TODO: assure single instance
	HWND hwnd = Create(NULL);
	return (int)hwnd;
}

int WeaselServer::Impl::StopServer()
{
	DestroyWindow();
	//quit the server
	::PostQuitMessage(0);
	return 0;
}

int WeaselServer::Impl::Run()
{
	CMessageLoop theLoop;
	_Module.AddMessageLoop(&theLoop);
	
	theLoop.AddMessageFilter(this);
	theLoop.AddIdleHandler(this);

	int nRet = theLoop.Run();

	theLoop.RemoveMessageFilter(this);
	theLoop.RemoveIdleHandler(this);
	
	_Module.RemoveMessageLoop();
	return nRet;
}

void WeaselServer::Impl::RegisterRequestHandler(WeaselServer::RequestHandler handler)
{
	m_handler = handler;
}

LRESULT WeaselServer::Impl::OnClientEcho(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM lParam, BOOL& /*bHandled*/)
{
	// TODO: lookup clientID
	// client not registered
	return 0;
}

LRESULT WeaselServer::Impl::OnAddClient(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	// TODO: 
	return 0;
}

LRESULT WeaselServer::Impl::OnRemoveClient(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM lParam, BOOL& /*bHandled*/)
{
	// TODO: 
	return 0;
}

LRESULT WeaselServer::Impl::OnKeyEvent(UINT /*uMsg*/, WPARAM wParam, LPARAM lParam, BOOL& /*bHandled*/)
{
	// TODO:
	return 0;
}

LRESULT WeaselServer::Impl::OnShutdownServer(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	StopServer();
	return 0;
}