#pragma once

#include "CoreMinimal.h"
#include "ChatGPTType.generated.h"
//此列定义基础的数据类型 枚举或者结构体
UENUM(BlueprintType)
enum class EGPTMode:uint8
{
	GPT_INVALID UMETA(DisPlayName = "invalid"),
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
	float Temperature;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CompletionParam")
	float Top_P;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CompletionParam")
	int32 N;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CompletionParam")
	bool bStream;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CompletionParam")
	FString Stop;

	
};

//USTRUCT(BlueprintType)
//struct CHATGPT_API FChatGPTCompletionResponses {
//	GENERATED_USTRUCT_BODY()
//
//	FChatGPTCompletionResponses();
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CompletionResponses")
//		FString ID;
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CompletionResponses")
//		FString Object;
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CompletionResponses")
//		int64 Created;
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CompletionResponses")
//		EGPTMode Model;
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CompletionResponses")
//		TArray<FChatGPTChoices> Choices;
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CompletionResponses")
//		FChatGPTUsage Usage;
//
//};
//USTRUCT(BlueprintType)
//struct CHATGPT_API FChatGPTChoices {
//	GENERATED_USTRUCT_BODY()
//
//	FChatGPTChoices();
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Choices")
//		FString Text;
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Choices")
//		int32 Index;
//};
//USTRUCT(BlueprintType)
//struct CHATGPT_API FChatGPTLogprobs {
//	GENERATED_USTRUCT_BODY()
//	FChatGPTLogprobs();
//	
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Logprobs")
//		TArray<FString> Tokens;
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Logprobs")
//		TArray<double> Token_logprobs;
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Logprobs")
//		TArray<int32> Text_offset;
//};
//USTRUCT(BlueprintType)
//struct CHATGPT_API FChatGPTUsage {
//	GENERATED_USTRUCT_BODY()
//	FChatGPTUsage();
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CompletionUsage")
//	int32 Prompt_tokens;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CompletionUsage")
//	int32 Completion_tokens;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CompletionUsage")
//	int32 Total_tokens;
//};