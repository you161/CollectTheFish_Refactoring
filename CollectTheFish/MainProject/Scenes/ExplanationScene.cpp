//
// ExplanationScene.cpp
//

#include "ExplanationScene.h"

using namespace HE;



// initialize member variables.
ExplanationScene::ExplanationScene()
{

}

// rearrange UI to fit the size.
void ExplanationScene::ResizeLayout()
{
    Scene::ResizeLayout();

}

// load resources.
void ExplanationScene::Load()
{
    m_sprite = Sprite("Explanation.png");
    RenderingPath->AddSprite(&m_sprite, -100);
    m_sprite.params.siz = Math::Vector2(1280.0f, 720.0f);
    
    bgm_ = Sound("Sound/Ex.wav", Sound::LoopCount::BGM);
    bgm_.PlayFromTop();


    sprite_red_ = Sprite("fish_red.png");
    RenderingPath->AddSprite(&sprite_red_, -50);
    sprite_red_.params.siz = Math::Vector2(64.0f,64.0f);

    sprite_brown_ = Sprite("fish_brown.png");
    RenderingPath->AddSprite(&sprite_brown_, -50);
    sprite_brown_.params.siz = Math::Vector2(64.0f, 64.0f);

    sprite_pink_ = Sprite("fish_pink.png");
    RenderingPath->AddSprite(&sprite_pink_, -50);
    sprite_pink_.params.siz = Math::Vector2(64.0f, 64.0f);

    sprite_green_ = Sprite("fish_green.png");
    RenderingPath->AddSprite(&sprite_green_, -50);
    sprite_green_.params.siz = Math::Vector2(64.0f, 64.0f);

    sprite_blue_ = Sprite("fish_blue.png");
    RenderingPath->AddSprite(&sprite_blue_, -50);
    sprite_blue_.params.siz = Math::Vector2(128.0f, 128.0f);

    sprite_orange_ = Sprite("fish_orange.png");
    RenderingPath->AddSprite(&sprite_orange_, -50);
    sprite_orange_.params.siz = Math::Vector2(64.0f, 64.0f);


    score_headline_.params.style = Font::AddFontStyle("Fonts/msgothic002.ttf");
    RenderingPath->AddFont(&score_headline_, 1000);

    Scene::Load();
}

// initialize a variables.
void ExplanationScene::Initialize()
{
    sprite_red_.params.pos    = Math::Vector2(192.0f, 656.0f);
    sprite_brown_.params.pos  = Math::Vector2(384.0f, 656.0f);
    sprite_pink_.params.pos   = Math::Vector2(576.0f, 656.0f);
    sprite_green_.params.pos  = Math::Vector2(768.0f, 656.0f);
    sprite_blue_.params.pos   = Math::Vector2(960.0f, 656.0f);
    sprite_orange_.params.pos = Math::Vector2(1152.0f, 656.0f);
 

    score_headline_.SetText(L"Å™[É^ÉCÉgÉã]");
    score_headline_.params.posX = 1000.0f;
    score_headline_.params.posY = 60.0f;
    score_headline_.params.size = 60;
    score_headline_.params.color = Color(255, 255, 255);    // ê‘, óŒ, ê¬(0-255
}

// releasing resources required for termination.
void ExplanationScene::Terminate()
{

}

// updates the scene.
void ExplanationScene::Update(float deltaTime)
{

    if (InputSystem.Keyboard.isPressed.Up) {
        SceneManager.SetNextScene(NextScene::StartScene); 
    }

    Scene::Update(deltaTime);
}

