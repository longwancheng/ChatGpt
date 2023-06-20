#include "Core/ChatGptMethod.h"

#include "Policies/CondensedJsonPrintPolicy.h"
#include "Serialization/JsonWriter.h"

namespace ChatGPTMethod
{
	//将枚举转换为字符串 
	FString EGPTModeToString(EGPTMode InMode)
	{
		switch(InMode)
		{
		case EGPTMode::DAVINCI_003:
			return TEXT("text_davinci_003");
		default:
			return TEXT("");
		}
		return TEXT("");
	}
	//将数据写入并转换成字符串
	void ChatGPTCompletionParamToString(const FChatGPTCompletionParam& InParam,FString& OutJson)
	{
		TSharedPtr<TJsonWriter<TCHAR,TCondensedJsonPrintPolicy<TCHAR>>> JsonWriter =
			TJsonWriterFactory<TCHAR,TCondensedJsonPrintPolicy<TCHAR>>::Create(&OutJson);
		JsonWriter->WriteObjectStart();
		{
			//写入数据
			JsonWriter->WriteValue(TEXT("model"),EGPTModeToString(InParam.Mode));
			JsonWriter->WriteValue(TEXT("prompt"),InParam.Prompt);
			JsonWriter->WriteValue(TEXT("max_tokens"),InParam.MaxTokens);
			JsonWriter->WriteValue(TEXT("temperature"),InParam.Temperature);
			JsonWriter->WriteValue(TEXT("top_p"),InParam.Top_P);
			JsonWriter->WriteValue(TEXT("n"),InParam.N);
			JsonWriter->WriteValue(TEXT("stream"),InParam.bStream);
			JsonWriter->WriteValue(TEXT("logprobs"),NULL);
			JsonWriter->WriteValue(TEXT("stop"),InParam.Stop);
		}
		JsonWriter->WriteObjectEnd();
		JsonWriter->Close();//Json合并
				
	}

}
