#include "TimeManager.h"

void TimeManager::Load()
{
    time_headline_.params.style = Font::AddFontStyle("Fonts/msgothic002.ttf");
    RenderingPath->AddFont(&time_headline_, 1000);
    time_text_.params.style = Font::AddFontStyle("Fonts/msgothic002.ttf");
    RenderingPath->AddFont(&time_text_, 1000);
}

void TimeManager::Initialize(float game_time)
{
    count_time_ = game_time;

    time_headline_.SetText(L"TIME : ");
    time_headline_.params.posX = 900.0f;
    time_headline_.params.posY = 30.0f;
    time_headline_.params.size = 80;
    time_headline_.params.color = HE::Color(255, 255, 255);    // ê‘, óŒ, ê¬(0-255)

    time_text_.SetText(std::to_string(count_time_));
    time_text_.params.posX = 1120.0f;
    time_text_.params.posY = 30.0f;
    time_text_.params.size = 80;
    time_text_.params.color = HE::Color(255, 0, 0);
}

void TimeManager::Update()
{
    if (count_time_ <= 0.0f && !is_gameover_) {
        is_gameover_ = true;
    }
    else {
        count_time_ -= Time.deltaTime;
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(0) << count_time_;
        time_text_.SetText(oss.str());
    }
}