#pragma once

#include "CoreMinimal.h"
#include "HTTP/ChatGptHttp.h"
#include "ChatGPTObject.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FHttpChatGPTResponseDelegate,const TArray<FString>&,InData,const FString&,InMsg);

UCLASS(BlueprintType,Blueprintable)
class CHATGPT_API UChatGPTObject: public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintAssignable)
	FHttpChatGPTResponseDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FHttpChatGPTResponseDelegate OnFailure;
public:
	UFUNCTION(BlueprintCallable,meta=(DisplayName = "CreateChatGPTObject",Keywords = "GPT"),Category="ChatGPT")
	static UChatGPTObject* CreateObject(UClass* InClass = NULL,UObject* InParent = NULL);
	
	UFUNCTION(BlueprintCallable,Category="ChatGPT")
	bool Request(const FString &InURL
			,const FString& InContent
			,TMap<FString,FString> &InCustomMetaDataHeader
			);

	UFUNCTION(BlueprintPure,Category="ChatGPT")
	bool IsLeaveUnused()const;

	UFUNCTION(BlueprintCallable,Category="ChatGPT")
	void SetOpenAIKey(const FString &InKey);
private:
	void OnRequestComplete(FHttpRequestPtr HttpRequest,FHttpResponsePtr HttpResponse,bool bSuccessed);
public:
	UChatGPTObject();
protected:
	void InitChatGPT();
private:
	TSharedPtr<ChatGPTHTTP::FHTTP>HTTP;
};

