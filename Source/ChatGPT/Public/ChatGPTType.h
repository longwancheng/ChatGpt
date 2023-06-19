#pragma once

#include "CoreMinimal.h"
#include "ChatGPTType.generated.h"

enum  class EGPTMode:uint8
{
	DAVINCI_003 UMETA(DisPlayName = "text-davinci-003"),
	GPT_MAX,
};

USTRUCT(BlueprintType)
struct CHATGPT_API FChatGPTCompletionParam
{
	GENERATED_USTRUCT_BODY()

	FChatGPTCompletionParam();
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CompletionParam")
	EGPTMode Mode;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CompletionParam")
	FString Prompt;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CompletionParam")
	int32 MaxTokens;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CompletionParam")
	int32 Temperature;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CompletionParam")
	float Top_P;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CompletionParam")
	int32 N;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CompletionParam")
	bool bStream;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CompletionParam")
	FString Stop;

	
};
