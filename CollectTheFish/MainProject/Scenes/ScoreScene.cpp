//
// ScoreScene.cpp
//

#include "ScoreScene.h"
#include"DontDestroyOnLoad.h"


using namespace HE;

// initialize member variables.
ScoreScene::ScoreScene()
{
   
}

// rearrange UI to fit the size.
void ScoreScene::ResizeLayout()
{
    Scene::ResizeLayout();
}

// load resources.
void ScoreScene::Load()
{
    m_sprite = Sprite("ScoreScene.png");
    RenderingPath->AddSprite(&m_sprite, 0);
    m_sprite.params.siz = Math::Vector2(1280.0f, 720.0f);

    bgm_ = Sound("Sound/scorebgm.wav", Sound::LoopCount::BGM);
    bgm_.PlayFromTop();

    se_ = Sound("Sound/TimeUp.wav", Sound::LoopCount::SE);
    se_.PlayFromTop();

   
    
    player_.Load();
    DontDestroy.m_score.Load();
 
    Scene::Load();
}

// initialize a variables.
void ScoreScene::Initialize()
{
    player_.Initialize();

}

// releasing resources required for termination.
void ScoreScene::Terminate()
{

}

// updates the scene.
void ScoreScene::Update(float deltaTime)
{
    player_.Update();
    
    if (InputSystem.Keyboard.isPressed.Enter) {
       
        SceneManager.SetNextScene(NextScene::StartScene);
    }

    if (InputSystem.Keyboard.isPressed.Space) {
        se_ = Sound("Sound/Continue.wav", Sound::LoopCount::SE);
        se_.PlayFromTop();

        SceneManager.SetNextScene(NextScene::MainScene);
    }

    Scene::Update(deltaTime);
}



