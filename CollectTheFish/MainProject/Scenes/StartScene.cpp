//
// StartScene.cpp
//

#include "StartScene.h"
#include<iostream>


using namespace HE;



// initialize member variables.
StartScene::StartScene()
{

}

// rearrange UI to fit the size.
void StartScene::ResizeLayout()
{
    Scene::ResizeLayout();

}

// load resources.
void StartScene::Load()
{
    m_sprite = Sprite("Titlea.png");
    RenderingPath->AddSprite(&m_sprite, 0);
    m_sprite.params.siz = Math::Vector2(1280.0f, 720.0f);
    
    bgm_ = Sound("Sound/titlebgm.wav", Sound::LoopCount::BGM);
    bgm_.PlayFromTop();

    score_headline_.params.style = Font::AddFontStyle("Fonts/msgothic002.ttf");
    RenderingPath->AddFont(&score_headline_, 1000);


    Scene::Load();
}

// initialize a variables.
void StartScene::Initialize()
{
    score_headline_.SetText(L"«[—V‚Ñ•û]");
    score_headline_.params.posX = 1000.0f;
    score_headline_.params.posY = 600.0f;
    score_headline_.params.size = 60;
    score_headline_.params.color = Color(255, 255, 255);    // Ô, —Î, Â(0-255
}

// releasing resources required for termination.
void StartScene::Terminate()
{

}

// updates the scene.
void StartScene::Update(float deltaTime)
{

    if (InputSystem.Keyboard.isPressed.Space) {
        SceneManager.SetNextScene(NextScene::MainScene); 
    }

    if (InputSystem.Keyboard.isPressed.Down) {
        SceneManager.SetNextScene(NextScene::ExplanationScene);
    }


    Scene::Update(deltaTime);
}

