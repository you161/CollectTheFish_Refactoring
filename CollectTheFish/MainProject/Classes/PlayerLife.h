
//PlayerLife.h

#pragma once

#include "../HuEngine.h"

class PlayerLife {
public:
    void Load();
    void Initialize();

    void SetLife();

    int GetLife() const { return rest_; }
    void SetLife(int life) { rest_ = life; score_text_.SetText(std::to_string(rest_)); }

private:
    int rest_;
    HE::SpriteFont score_headline_;
    HE::SpriteFont score_text_;
};