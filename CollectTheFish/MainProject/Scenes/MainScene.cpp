
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

    fishmanager_[red].Load("fish_red",1);
    fishmanager_[orange].Load("fish_orange", 1);
    fishmanager_[blue].Load("fish_blue", 1);
    fishmanager_[green].Load("fish_green", 1);
    fishmanager_[pink].Load("fish_pink", 1);


    bg_.    Load();
    /*a_.Load();
    fo_.    Load();
    fb_.    Load();
    fg_.    Load();
    fp_.    Load();*/
    fB_.    Load();
    fBA_.   Load();
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

    fishmanager_[red].Initialize(Vector2(64.0f, 64.0f), Vector2(-64.0f, 300.0f));
    fishmanager_[orange].Initialize(Vector2(64.0f, 64.0f), Vector2(-64.0f, 680.0f));
    fishmanager_[blue].Initialize(Vector2(128.0f, 128.0f), Vector2(-128.0f, 500.0f));
    fishmanager_[green].Initialize(Vector2(64.0f, 64.0f), Vector2(-64.0f, 600.0f));
    fishmanager_[pink].Initialize(Vector2(64.0f, 64.0f), Vector2(-64.0f, 200.0f));


   /* a_.Initialize(Math::Vector2(-64.0f,300.0f));
    fo_.Initialize();
    fb_.Initialize();
    fg_.Initialize();
    fp_.Initialize(Math::Vector2(-64.0f * 1.0f,200.0f));*/
    fB_.Initialize();
    fBA_.Initialize();

    score_.Initialize();
    playerlife_.Initialize();

    collision_detect_.AddGroupList(L"Player", &player_);

    for (int i = 0; i < size(fishmanager_); i++) {
        collision_detect_.AddGroupList(L"Fish", &fishmanager_[i]);
    }
    
    player_.CollisionProc = [this]()
        {
            AddScore(50);
            player_.SetPosition();
        };
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
        AddScore(10);
    }

    if (player_collision.Intersects(fo_collision)) {
        fo_.OnCollision();
        AddScore(30);
    }

    if (player_collision.Intersects(fb_collision)) {
        fb_.OnCollision();
        AddScore(20);
    }

    if (player_collision.Intersects(fg_collision)) {
        fg_.OnCollision();
        AddScore(50);
    }

    if (player_collision.Intersects(fp_collision)) {
        fp_.OnCollision();
        AddScore(5);
    }

    if (player_collision.Intersects(fB_collision)) {
        fB_.OnCollision();
        AddScore(-50);
    }

    if (player_collision.Intersects(fBA_collision)) {
        fBA_.OnCollision();
        AddScore(-50);
    }

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