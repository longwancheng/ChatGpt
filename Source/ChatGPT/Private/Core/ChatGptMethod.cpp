#include "Core/ChatGptMethod.h"

#include "Policies/CondensedJsonPrintPolicy.h"
#include "Serialization/JsonWriter.h"

namespace ChatGPTMethod
{
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

	void ChatGPTCompletionParamToString(const FChatGPTCompletionParam& InParam,FString& OutJson)
	{
		TSharedPtr<TJsonWriter<TCHAR,TCondensedJsonPrintPolicy<TCHAR>>> JsonWriter =
			TJsonWriterFactory<TCHAR,TCondensedJsonPrintPolicy<TCHAR>>::Create(&OutJson);
		
	}

}
