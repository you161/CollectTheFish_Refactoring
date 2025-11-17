#pragma once

#include "../HuEngine.h"

class ExplanationScene : public HE::Scene
{
public:
    ExplanationScene();
    virtual ~ExplanationScene() { Terminate(); }

    void ResizeLayout() override;

    void Load() override;
    void Initialize() override;
    void Terminate() override;

    void Update(float deltaTime) override;

private:

    HE::Sprite m_sprite;
    HE::Sprite sprite_red_;
    HE::Sprite sprite_brown_;
    HE::Sprite sprite_pink_;
    HE::Sprite sprite_green_;
    HE::Sprite sprite_blue_;
    HE::Sprite sprite_orange_;
    HE::Sound bgm_;
    HE::Sound se_;

    HE::SpriteFont score_headline_;
};