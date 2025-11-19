
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

    
 
private:

    HE::Sprite sprite_R;
    HE::Sprite sprite_W;
    BG     bg_;
    HE::Sound bgm_;
    HE::Sound se_;
    int score_;
    NextScene nextScene_;
  
    HE::SpriteFont score_headline_;
    HE::SpriteFont score_text_;
    
    Player player_;

    FishRed a_;
    FishRed Aa_;
    FishOrange fo_;
    Fishblue fb_;
    Fishgreen fg_;
    Fishpink fp_;
    Fishpink fpA_;
    Fishpink fpB_;
    FishBrown fB_;
    FishBrownA fBA_;

    Score m_score;
    PlayerLife playerlife_;

};



