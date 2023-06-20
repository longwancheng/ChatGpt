#include "HTTP/ChatGptHttp.h"
#include "Core/ChatGptMethod.h"

namespace ChatGPTHTTP
{
	FHTTP::FHTTP(FHTTPDelegate InDelegate)
		:Delegate(InDelegate)//对成员函数Delegate进行初始化
	{
		bLeaveUnused = true;
	}

	bool FHTTP::Request(const FString& InURL
		,const FString& InContent
		,TMap<FString, FString>& InCustomMetaDataHeader
		,EHTTPVerbType VerbType)
	{
		if(!OpenAIKey.IsEmpty())
		{
			if (bLeaveUnused)
			{
				bLeaveUnused = false;

				TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
				Request->SetURL(InURL);

				Request->SetHeader(TEXT("Content-Type"),FString("application/json"));
				Request->SetHeader(TEXT("Authorization"),FString::Printf(TEXT("Bearer %s"),*OpenAIKey));
				
				for (auto& temp : InCustomMetaDataHeader) {
					Request->SetHeader(temp.Key,temp.Value);
				}
				//设置请求方式
				Request->SetVerb(HTTPVerbToString((VerbType)));
				//设置请求内容
				Request->SetContentAsString(InContent);
				//绑定委托
				Request->OnProcessRequestComplete().BindSP(this,&FHTTP::OnRequestComplete);
				//发出请求
				Request->ProcessRequest();
				return true;
			}
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
	
	void FHTTP::OnRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HHttpRequest, bool bSuccessed)
	{
		bLeaveUnused = true;
		Delegate.CompleteDelegate.ExecuteIfBound(HttpRequest,HHttpRequest,bSuccessed);
	}

	bool FHTTP::Request(const FString& InURL, const FChatGPTCompletionParam& InCompletionParam,
		TMap<FString, FString>& InCustomMetaDataHeader, EHTTPVerbType VerbType)
	{
		FString ParamJson;
		ChatGPTMethod::ChatGPTCompletionParamToString(InCompletionParam,ParamJson);
		return Request(InURL,ParamJson,InCustomMetaDataHeader,VerbType);
	}
	
}