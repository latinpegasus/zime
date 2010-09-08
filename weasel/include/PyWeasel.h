#pragma once
#include <WeaselIPC.h>
#include <boost/python.hpp>

struct PyWeasel
{
	static void Initialize();
	static void Finalize();
};

class PyWeaselHandler :
	public weasel::RequestHandler
{
public:
	PyWeaselHandler();
	virtual ~PyWeaselHandler();
	virtual UINT FindSession(UINT sessionID);
	virtual UINT AddSession(LPWSTR buffer);
	virtual UINT RemoveSession(UINT sessionID);
	virtual BOOL ProcessKeyEvent(weasel::KeyEvent keyEvent, UINT sessionID, LPWSTR buffer);

private:
	bool _Respond(LPWSTR buffer, std::wstring const& msg);
	boost::python::object m_service;
};