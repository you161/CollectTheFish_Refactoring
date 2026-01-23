
//MainScean.h

#pragma once

#include "../HuEngine.h"
#include "../Classes/BG.h"
#include "../Classes/Player.h"
#include "../Classes/FishRed.h"
#include "../Classes/Fishblue.h"
#include "../Classes/FishBrown.h"
#include "../Classes/FishBrownA.h"
#include "../Classes/Fishgreen.h"
#include "../Classes/Fishpink.h"
#include "../Classes/FishOrange.h"
#include "../Classes/Score.h"
#include "../Classes/PlayerLife.h"
#include"../Scenes/ScoreScene.h"
#include"../Scenes/StartScene.h"
#include"../Classes/CollisionDetection.h"
#include"../Classes/FishManager.h"

using namespace HE;
using namespace Math;


class MainScene : public HE::Scene
{
public:
    MainScene();
    virtual ~MainScene() { Terminate(); }
    void ResizeLayout() override;
    void Load() override;
    void Initialize() override;
    void Terminate() override;
    void Update(float deltaTime) override;

    void AddScore(int point);
 
private:
    Sound bgm_;
    Sound se_;
    Sound time_se_;

    Sprite sprite_R;
    Sprite sprite_W;
    SpriteFont score_headline_;
    SpriteFont score_text_;
    
    NextScene nextScene_;
    BG     bg_;
    Player player_;

    FishRed a_;
    FishRed Aa_;
    FishOrange fo_;
    Fishblue fb_;
    Fishgreen fg_;
    Fishpink fp_;

    FishBrown fB_;
    FishBrownA fBA_;

    Score score_;
    PlayerLife playerlife_;
    CollisionDetection collision_detect_;

    FishManager fishmanager_[5];
    int red = 0;
    int orange = 1;
    int blue = 2;
    int green = 3;
    int pink = 4;
};



