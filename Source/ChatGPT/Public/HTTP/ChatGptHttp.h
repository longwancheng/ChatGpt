#pragma once

#include "CoreMinimal.h"
#include "Http.h"

namespace ChatGPTHTTP
{
	enum EHTTPVerbType
	{
		POST,
		PUT,
		GET,
		DELETE,
	};
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
		
		static TSharedPtr<FHTTP> CreateHTTPObject(FHTTPDelegate InDelegate);
	public:
		bool IsLeaveUnused()const{ return bLeaveUnused;};
		
		void SetOpenAIKey(const FString &OpenAIKey){this->OpenAIKey = OpenAIKey;};
	private:
		void OnRequestComplete(FHttpRequestPtr HttpRequest,FHttpResponsePtr HttpResponse,bool bSuccessed);
		
	private:
		FString HTTPVerbToString(EHTTPVerbType InVerbType);
		
	private:
		FString OpenAIKey;
		bool bLeaveUnused;//是否闲置
		FHTTPDelegate Delegate;
	};
}
