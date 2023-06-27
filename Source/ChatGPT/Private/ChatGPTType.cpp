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
//FChatGPTChoices::FChatGPTChoices() {
//	Index = INDEX_NONE;
//}
//
//FChatGPTUsage::FChatGPTUsage() {
//	Prompt_tokens = INDEX_NONE;
//	Completion_tokens = INDEX_NONE;
//	Total_tokens = INDEX_NONE;
//}
//
//FChatGPTCompletionResponses::FChatGPTCompletionResponses() {
//	Created = INDEX_NONE;
//	Model = EGPTMode::GPT_INVALID;
//
//}