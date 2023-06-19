#include "ChatGPTType.h"

FChatGPTCompletionParam::FChatGPTCompletionParam()
{
	Mode = EGPTMode::DAVINCI_003;
	MaxTokens = 300;
	Temperature = 0.5f;
	Top_P = 1.f;
	N = 1;
	bStream = false;
	Stop =TEXT("\n");
};