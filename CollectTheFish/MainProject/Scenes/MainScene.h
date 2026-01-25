
//MainScean.h

#pragma once

#include "../HuEngine.h"
#include "../Classes/BG.h"
#include "../Classes/Player.h"
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
    FishManager fishmanager_;
    Score score_;
    PlayerLife playerlife_;
    CollisionDetection collision_detect_;
};



