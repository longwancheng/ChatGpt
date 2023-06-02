#include "HTTP/ChatGptHttp.h"

namespace ChatGPTHTTP
{
	FHTTP::FHTTP(FHTTPDelegate InDelegate)
		:Delegate(InDelegate)
	{
		bLeaveUnused = true;
	}

	bool FHTTP::Request(const FString& InURL
		,const FString& InContent
		,TMap<FString, FString>& InCustomMetaDataHeader
		,EHTTPVerbType VerbType)
	{
		if(bLeaveUnused)
		{
			bLeaveUnused = false;
		}

		return false;
	}

	TSharedPtr<FHTTP> FHTTP::CreateHTTPObject(FHTTPDelegate InDelegate)
	{
		return MakeShareable(new FHTTP(InDelegate));
	}

	FString FHTTP::HTTPVerbToString(EHTTPVerbType InVerbType)
	{
		switch (InVerbType)
		{
		case ChatGPTHTTP::POST:
			return TEXT("POST");
		case ChatGPTHTTP::PUT:
			return TEXT("PUT");
		case ChatGPTHTTP::GET:
			return TEXT("GET");
		case ChatGPTHTTP::DELETE:
			return TEXT("DELETE");
		}
		return TEXT("POST");
	}

	void FHTTP::OnRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSuccessed)
	{
		
	}

}