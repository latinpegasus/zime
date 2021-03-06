#pragma once
#include <WeaselCommon.h>
#include <windows.h>
#include <map>
#include <string>
#include <boost/function.hpp>
#include <boost/smart_ptr.hpp>


namespace weasel
{
	class Deserializer;

	// 解析server回應文本
	struct ResponseParser
	{
		std::map<std::wstring, boost::shared_ptr<Deserializer> > deserializers;

		std::wstring& r_commit;
		Context& r_context;
		Status& r_status;

		// 以引用做參數初始化, 以求直接更新目標數據對象, 不做無謂的對象拷貝!
		ResponseParser(std::wstring& commit, Context& context, Status& status);

		// 重載函數調用運算符, 以扮做ResponseHandler
		bool operator() (LPWSTR buffer, UINT length);

		// 處理一行回應文本
		void Feed(const std::wstring& line);
	};

}
