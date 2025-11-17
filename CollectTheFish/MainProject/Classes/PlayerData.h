
//PlaterData.h

#pragma once

#include "../HuEngine.h"

class PlayerData {
public:
    void Load();
    void Initialize();
    int  GetScore() const { return score_; }
    void SetScore(int score);

private:
    int score_;
    HE::SpriteFont score_headline_;
    HE::SpriteFont score_text_;
};