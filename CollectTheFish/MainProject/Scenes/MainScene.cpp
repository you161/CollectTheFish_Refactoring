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

    fishManager_.Load(fishParams);


    bg_.    Load();
    score_.Load();
    timeManager_.Load();
    bgm_.PlayFromTop();

    Scene::Load();
}

void MainScene::Initialize()
{
    bg_.Initialize();
    player_.Initialize();
    score_.Initialize();
    timeManager_.Initialize(30);

    collision_detect_.AddGroupList(L"Player", &player_);

    fishManager_.Initialize();

    for (auto& fish : fishManager_.GetFishList())
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
    player_.Update();
    fishManager_.Update();
    timeManager_.Update();
    collision_detect_.Detect(L"Player", L"Fish");

    if (timeManager_.GetTimeFlag()) {
        DontDestroy.m_score = score_;
        SceneManager.SetNextScene(NextScene::ScoreScene);
    }

    Scene::Update(deltaTime);
}

void MainScene::AddScore(int point) 
{
    int score = score_.GetScore();
    score += point;
    score_.SetScore(score);
    se_.PlayFromTop();
}