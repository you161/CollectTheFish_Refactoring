//
//FishRed.cpp
//

#include "FishRed.h"

using namespace HE;

void FishRed::Load()
{
	SpriteObject::Load("fish_red.png", -50);
    RenderingPath->AddSprite(&collision_sprite_, 1);
}

void FishRed::Initialize(HE::Math::Vector2 initial)
{
	SpriteObject::Initialize(Vector2(64.0f, 64.0f), Vector2(0.0f, 0.0f));
    SetInitialPosition();
    collision_sprite_.params.color = HE::Color(0, 0, 255);
    collision_sprite_.params.opacity = 0.0f;

}

void FishRed::Update()
{
    fishMovement.Movement(m_sprite.params.pos,m_sprite.params.siz,270.0f,1);
    m_sprite.params.pos.x += 270.0f * Time.deltaTime;
    if (m_sprite.params.pos.x >= 1280.0f) {
        m_sprite.params.pos = Math::Vector2(-80.0f,Random::GetRandom(100.0f, 400.0f));
    }
      
}

Math::Rectangle FishRed::GetCollision()
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

void FishRed::OnCollision()
{
    m_sprite.params.pos = Math::Vector2(-80.0f, Random::GetRandom(100.0f, 400.0f));
}

void FishRed::SetInitialPosition()
{
    m_sprite.params.pos = Math::Vector2(-80.0f, 300.0f);
}