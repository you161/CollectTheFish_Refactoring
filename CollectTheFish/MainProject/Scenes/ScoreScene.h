
#pragma once

#include <iostream>

#include "../HuEngine.h"
#include "../Classes/Player.h"
#include "../Scenes/MainScene.h"
#include "../Classes/PlayerData.h"

using namespace std;

class ScoreScene : public HE::Scene
{
public:
    ScoreScene();
    virtual ~ScoreScene() { Terminate(); }

    void ResizeLayout() override;

    void Load() override;
    void Initialize() override;
    void Terminate() override;

    void Update(float deltaTime) override;

private:
    HE::Sprite m_sprite;
    HE::Sound bgm_;
    HE::Sound se_;
    Player player_;
    PlayerData playerdata_;

};