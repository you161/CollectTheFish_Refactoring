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

    bgm_     = Sound("Sound/mainbgm.wav", Sound::LoopCount::BGM);
    se_      = Sound("Sound/PushA.wav", Sound::LoopCount::SE);
    time_se_ = Sound("Sound/Time.wav", Sound::LoopCount::SE);

    player_.Load();

    std::vector<FishParam> fishParams =
    {
        { "fish_red.png",Vector2(64.0f,64.0f),    125.0f,  1,  20,  {-80,300}, true },
        { "fish_orange.png",Vector2(64.0f,64.0f), 200.0f,  1,  30,  {-80,560}, true },
        { "fish_blue.png", Vector2(128.0f,128.0f),  100.0f,  1,  30,  {-140,500}, true },
        { "fish_green.png", Vector2(64.0f,64.0f), 50.0f,  1,  50,  {-80,600}, true },
        { "fish_brown.png", Vector2(64.0f,64.0f), 150.0f,  1, -50,  {-80,250}, true },
        { "fish_brown.png", Vector2(64.0f,64.0f), 150.0f,  -1, -50,  {1380,400}, true },
        { "fish_pink.png", Vector2(64.0f,64.0f), 250.0f,  1, 10,  {-80,200}, true }
    };

    fishmanager_.Load(fishParams);


    bg_.    Load();
    score_.Load();
    playerlife_.Load();
    bgm_.PlayFromTop();

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

    score_.Initialize();
    playerlife_.Initialize();

    collision_detect_.AddGroupList(L"Player", &player_);

    fishmanager_.Initialize();

    for (auto& fish : fishmanager_.GetFishList())
    {
        fish.CollisionProc = [this](int point)
            {
                AddScore(point);

                if (point < 0) {
                    player_.SetPosition();
                }
            };

        collision_detect_.AddGroupList(L"Fish", &fish);
    }
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
            time_se_.PlayFromTop();
        }

        if (rest < 0) {
            DontDestroy.m_score = score_;
            SceneManager.SetNextScene(NextScene::ScoreScene);
        }
    }

    player_.Update();
    fishmanager_.Update();

    collision_detect_.Detect(L"Player", L"Fish");

    Scene::Update(deltaTime);
}

void MainScene::AddScore(int point) 
{
    int score = score_.GetScore();
    score += point;
    score_.SetScore(score);
    se_.PlayFromTop();
}