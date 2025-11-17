//
//FishBrown.cpp
//

#include "FishBrown.h"

using namespace HE;

void FishBrown::Load()
{
	SpriteObject::Load("fish_brown.png", -50);;
    RenderingPath->AddSprite(&collision_sprite_, 1);
}

void FishBrown::Initialize()
{
	SpriteObject::Initialize(Vector2(64.0f, 64.0f), Vector2(0.0f, 0.0f));
    SetInitialPosition();
    collision_sprite_.params.color = HE::Color(0, 0, 255);
    collision_sprite_.params.opacity = 0.0f;
}

void FishBrown::Update()
{

    m_sprite.params.pos.x += 400.0f * Time.deltaTime;
    if (m_sprite.params.pos.x >= 1280.0f)
        m_sprite.params.pos = Math::Vector2(-80.0f, Random::GetRandom(50.0f,680.0f));
}

Math::Rectangle FishBrown::GetCollision()
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

void FishBrown::OnCollision()
{
    m_sprite.params.pos = Math::Vector2(-80.0f, Random::GetRandom(50.0f, 680.0f));
}

void FishBrown::SetInitialPosition()
{
    m_sprite.params.pos = Math::Vector2(-80.0f, 400.0f);
}