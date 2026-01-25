
//MainScean.h

#pragma once

#include "../HuEngine.h"
#include "../Classes/BG.h"
#include "../Classes/Player.h"
#include "../Classes/Score.h"
#include"../Scenes/ScoreScene.h"
#include"../Scenes/StartScene.h"
#include"../Classes/CollisionDetection.h"
#include"../Classes/FishManager.h"
#include"../Classes/TimeManager.h"
#include"../Classes/SEManager.h"

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
    NextScene nextScene_;
    BG     bg_;
    Player player_;
    FishManager fishManager_;
    Score score_;
    TimeManager timeManager_;
    SEmanager seManager_;
    CollisionDetection collision_detect_;
};