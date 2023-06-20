#pragma once

#include "CoreMinimal.h"
#include "ChatGPTType.h"
#include "Http.h"

namespace ChatGPTHTTP
{
	//HTTP请求的几种方式
	enum EHTTPVerbType
	{
		POST,
		PUT,
		GET,
		DELETE,
	};
	//定义HTTP请求需要的代理
	struct FHTTPDelegate
	{
		FHttpRequestCompleteDelegate CompleteDelegate;
	};
	
	struct FHTTP : public TSharedFromThis<FHTTP>
	{
		FHTTP(FHTTPDelegate InDelegate);
		//向服务器发送请求
		bool Request(const FString &InURL
			,const FString &InContent
			,TMap<FString,FString> &InCustomMetaDataHeader
			,EHTTPVerbType VerbType = EHTTPVerbType::POST);
		//向服务器发送请求
		bool Request(const FString &InURL
			,const FChatGPTCompletionParam &InCompletionParam
			,TMap<FString,FString> &InCustomMetaDataHeader
			,EHTTPVerbType VerbType = EHTTPVerbType::POST);
		
		static TSharedPtr<FHTTP> CreateHTTPObject(FHTTPDelegate InDelegate);

		bool IsLeaveUnused()const{ return bLeaveUnused;};
		
		void SetKey(const FString &Key){OpenAIKey = Key;};

		
	private:
		void OnRequestComplete(FHttpRequestPtr HttpRequest,FHttpResponsePtr HttpResponse,bool bSuccessed);
		
		FString HTTPVerbToString(EHTTPVerbType InVerbType);
		
		FString OpenAIKey;
		
		bool bLeaveUnused;//是否闲置
		
		FHTTPDelegate Delegate;
	};
}
