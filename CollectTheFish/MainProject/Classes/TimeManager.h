#pragma once
#include "../HuEngine.h"

using namespace HE;
using namespace Math;
using namespace std;

class TimeManager
{
public:
    void Load();
    void Initialize(float game_time);
    void Update();
    bool GetTimeFlag() { return is_gameover_; }
private:
    float count_time_ = 0;
    bool is_gameover_ = false;
    SpriteFont time_headline_;
    SpriteFont time_text_;
};