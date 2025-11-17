
//PlayerLife.cpp

#include "PlayerLife.h"

using namespace HE;



void PlayerLife::Load()
{
    score_headline_.params.style = Font::AddFontStyle("Fonts/msgothic002.ttf");
    score_text_.params.style = Font::AddFontStyle("Fonts/msgothic002.ttf");

    RenderingPath->AddFont(&score_headline_, 1000);
    RenderingPath->AddFont(&score_text_, 1000);
}

void PlayerLife::Initialize()
{
    rest_ = 3;

    // スコア見出し(1-UP)
    score_headline_.SetText(L"TIME");
    score_headline_.params.posX = 1034.0f;
    score_headline_.params.posY = 30.0f;
    score_headline_.params.size = 50;
    score_headline_.params.color = Color(255, 255, 255);    // 赤, 緑, 青(0-255)

    // スコア数値
    score_text_.SetText(std::to_string(rest_));
    score_text_.params.posX = 1065.0f;
    score_text_.params.posY = 80.0f;
    score_text_.params.size = 100;
    score_text_.params.color = Color(255, 0, 0);
}

void PlayerLife::SetLife()
{
    rest_--;
    score_text_.SetText(std::to_string(rest_));
}