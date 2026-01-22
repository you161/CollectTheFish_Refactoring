
//
// MainScene.cpp
//

#include "MainScene.h"
#include"DontDestroyOnLoad.h"

using namespace HE;
using namespace std;

MainScene::MainScene()
{

}

void MainScene::ResizeLayout()
{
    Scene::ResizeLayout();
}

void MainScene::Load()
{

    sprite_R = Sprite("TimeRed.png");
    RenderingPath->AddSprite(&sprite_R, -50);
    sprite_W = Sprite("TimeWhite.png");
    RenderingPath->AddSprite(&sprite_W, -50);

    player_.Load();
    bg_. Load();
    a_.  Load();
    fo_. Load();
    fb_. Load();
    fg_. Load();
    fp_. Load();
    fB_. Load();
    fBA_.Load();
    m_score.Load();
    playerlife_.Load();

    bgm_ = Sound("Sound/mainbgm.wav", Sound::LoopCount::BGM);
    bgm_.PlayFromTop();

    se_ = Sound("Sound/PushA.wav", Sound::LoopCount::SE);

    Scene::Load();
}

void MainScene::Initialize()
{

    sprite_R.params.siz = Math::Vector2(1280.0f, 25.0f);
    sprite_R.params.pos = Math::Vector2(0.0f, 0.0f);

    sprite_W.params.siz = Math::Vector2(1280.0f, 25.0f);
    sprite_W.params.pos = Math::Vector2(0.0f, 0.0f);

    bg_.Initialize();
    player_.Initialize();
    a_.Initialize(Math::Vector2(-64.0f,300.0f));
    fo_.Initialize();
    fb_.Initialize();
    fB_.Initialize();
    fBA_.Initialize();
    fg_.Initialize();
    fp_.Initialize(Math::Vector2(-64.0f * 1.0f,200.0f));
    m_score.Initialize();
    playerlife_.Initialize();
}

void MainScene::Terminate()
{

}

void MainScene::Update(float deltaTime)
{ 


    sprite_W.params.pos.x += 150.0f * Time.deltaTime;
    if (sprite_W.params.pos.x >= 1280.0f) {
        sprite_W.params.pos.x = 0.0f;

        int rest = playerlife_.GetLife();
        rest -= 1;
        playerlife_.SetLife(rest);

        if (rest < 0) {
        }
        else {
            se_ = Sound("Sound/Time.wav", Sound::LoopCount::SE);
            se_.PlayFromTop();
        }
        
        if(rest < 0){
            DontDestroy.m_score = m_score;
            SceneManager.SetNextScene(NextScene::ScoreScene);
        }
    }


 player_.Update();
 a_.Update();
 fo_.Update();
 fb_.Update();
 fB_.Update();
 fBA_.Update();
 fg_.Update();
 fp_.Update();

 Math::Rectangle player_collision = player_.GetCollision();
 Math::Rectangle a_collision = a_.GetCollision();
 Math::Rectangle fo_collision = fo_.GetCollision();
 Math::Rectangle fb_collision = fb_.GetCollision();
 Math::Rectangle fB_collision = fB_.GetCollision();
 Math::Rectangle fBA_collision = fBA_.GetCollision();
 Math::Rectangle fg_collision = fg_.GetCollision();
 Math::Rectangle fp_collision = fp_.GetCollision();

 if (player_collision.Intersects(a_collision)) {
     a_.OnCollision();

     int score = m_score.GetScore();
     score += 10;
     m_score.SetScore(score);

     se_.PlayFromTop();
 }


 if (player_collision.Intersects(fo_collision)) {  
     fo_.OnCollision();

     int score = m_score.GetScore();
     score += 30;
     m_score.SetScore(score);

     se_.PlayFromTop();
 } 
 
 if (player_collision.Intersects(fb_collision)) {  
     fb_.OnCollision();

     int score = m_score.GetScore();
     score += 20;
     m_score.SetScore(score);

     se_.PlayFromTop();
 }

 if (player_collision.Intersects(fg_collision)) { 
     fg_.OnCollision();

     int score = m_score.GetScore();
     score += 50;
     m_score.SetScore(score);

     se_.PlayFromTop();
 }

 if (player_collision.Intersects(fp_collision)) {
     fp_.OnCollision();


     int score = m_score.GetScore();
     score += 5;
     m_score.SetScore(score);

     se_.PlayFromTop();
 }

 if (player_collision.Intersects(fB_collision)) {   
     fB_.OnCollision();

     int score = m_score.GetScore();
     score -= 50;
     m_score.SetScore(score);

     se_.PlayFromTop();
 }

 if (player_collision.Intersects(fBA_collision)) {
     fBA_.OnCollision();

     int score = m_score.GetScore();
     score -= 50;
     m_score.SetScore(score);

     se_.PlayFromTop();
 }
     Scene::Update(deltaTime);
}