//
//FishBrownA.cpp
//

#include "FishBrownA.h"

using namespace HE;

void FishBrownA::Load()
{

    m_sprite = Sprite("fish_brown.png");
    RenderingPath->AddSprite(&m_sprite, -50);
    RenderingPath->AddSprite(&collision_sprite_, 1);
}

void FishBrownA::Initialize()
{

    m_sprite.params.siz = Math::Vector2(64.0f, 64.0f);
    SetInitialPosition();
    m_sprite.params.enableDrawRect(Rectf(
        0, 0, m_sprite.params.siz.x, m_sprite.params.siz.y
    ));

    collision_sprite_.params.color = Color(0, 0, 255);
    collision_sprite_.params.opacity = 0.0f;

}

void FishBrownA::Update()
{

    m_sprite.params.pos.x -= 400.0f * Time.deltaTime;
    m_sprite.params.enableMirror();
    if (m_sprite.params.pos.x <= 0.0f)
        m_sprite.params.pos = Math::Vector2(1300.0f, Random::GetRandom(100.0f, 680.0f));
}

Math::Rectangle FishBrownA::GetCollision()
{
    Math::Rectangle collision;
    collision.x = (long)m_sprite.params.pos.x;
    collision.y = (long)m_sprite.params.pos.y;
    collision.width = (long)m_sprite.params.siz.x;
    collision.height = (long)m_sprite.params.siz.y;


    collision_sprite_.params.pos.x = (float)collision.x;
    collision_sprite_.params.pos.y = (float)collision.y;
    collision_sprite_.params.siz.x = (float)collision.width;
    collision_sprite_.params.siz.y = (float)collision.height;



    return collision;
}

void FishBrownA::OnCollision()
{
    m_sprite.params.pos = Math::Vector2(1300.0f, Random::GetRandom(100.0f, 680.0f));
}

void FishBrownA::SetInitialPosition()
{
    m_sprite.params.pos = Math::Vector2(1300.0f, 250.0f);
}