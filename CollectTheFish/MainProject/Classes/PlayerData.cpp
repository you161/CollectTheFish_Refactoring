
//
// PlayerData.cpp
//

#include "PlayerData.h"

using namespace HE;

void PlayerData::Load()
{
    score_headline_.params.style = Font::AddFontStyle("Fonts/msgothic002.ttf");
    score_text_.params.style = Font::AddFontStyle("Fonts/msgothic002.ttf");

    RenderingPath->AddFont(&score_headline_, 1000);
    RenderingPath->AddFont(&score_text_, 1000);
}

void PlayerData::Initialize()
{
    score_ = 0;

    // スコア見出し(1-UP)
    score_headline_.SetText(L"Score");
    score_headline_.params.posX = 440.0f;
    score_headline_.params.posY = 30.0f;
    score_headline_.params.size = 60;
    score_headline_.params.color = Color(255, 255, 255);    // 赤, 緑, 青(0-255)

    // スコア数値
    score_text_.SetText(std::to_string(score_));
    score_text_.params.posX = 460.0f;
    score_text_.params.posY = 80.0f;
    score_text_.params.size = 80;
    score_text_.params.color = Color(0, 0, 255);
}

void PlayerData::SetScore(int score)
{
    score_ = score;
    score_text_.SetText(std::to_string(score_));
}