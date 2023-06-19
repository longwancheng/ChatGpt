#pragma once

#include "CoreMinimal.h"
#include "ChatGPTType.h"

namespace ChatGPTMethod
{
	FString EGPTModeToString(EGPTMode InMode);

	void ChatGPTCompletionParamToString(const FChatGPTCompletionParam &InParam,const FString &OutJson);
}
