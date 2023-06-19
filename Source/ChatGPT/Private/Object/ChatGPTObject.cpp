#include "Object/ChatGPTObject.h"

UChatGPTObject::UChatGPTObject()
{
	
}

void UChatGPTObject::InitChatGPT()
{
	ChatGPTHTTP::FHTTPDelegate HTTPDelegate;
	HTTPDelegate.CompleteDelegate.BindLambda(
	[&](FHttpRequestPtr HttpRequest,FHttpResponsePtr HttpResponse,bool bSucceeded)
	{
		OnRequestComplete(HttpRequest,HttpResponse,bSucceeded);
	});
	
	HTTP = ChatGPTHTTP::FHTTP::CreateHTTPObject(HTTPDelegate);
}

UChatGPTObject* UChatGPTObject::CreateObject(UClass* InClass, UObject* InParent)
{
	if(InParent)
	{
		if(UChatGPTObject* Obj = NewObject<UChatGPTObject>(InParent,InClass))
		{
			Obj->InitChatGPT();
			return Obj;
		}
	}
	else
	{
		if(UChatGPTObject* Obj = NewObject<UChatGPTObject>(NULL,InClass))
		{
			Obj->InitChatGPT();
			Obj->AddToRoot();
			return Obj;
		}
	}
	return NULL;
}

bool UChatGPTObject::Request(const FString& InURL, const FString& InContent,
	TMap<FString, FString>& InCustomMetaDataHeader)
{
	return HTTP->Request(InURL,InContent,InCustomMetaDataHeader);
}

void UChatGPTObject::OnRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSuccessed)
{

	
}

bool UChatGPTObject::IsLeaveUnused() const
{
	return HTTP->IsLeaveUnused();
}

void UChatGPTObject::SetOpenAIKey(const FString& InKey)
{
	HTTP->SetKey(InKey);
}

