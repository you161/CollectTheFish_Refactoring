//
//Fishblue.cpp
//

#include "Fishblue.h"

using namespace HE;

void Fishblue::Load()
{
	SpriteObject::Load("fish_blueA.png", -50);
    RenderingPath->AddSprite(&collision_sprite_, 1);
}

void Fishblue::Initialize()
{
	SpriteObject::Initialize(Vector2(128.0f, 128.0f), Vector2(0.0f, 0.0f));
    SetInitialPosition();
    collision_sprite_.params.color = HE::Color(0, 0, 255);
    collision_sprite_.params.opacity = 0.0f;
}

void Fishblue::Update()
{

    m_sprite.params.pos.x += 150.0f * Time.deltaTime;
    if (m_sprite.params.pos.x >= 1280.0f)
        m_sprite.params.pos = Math::Vector2(-140.0f, Random::GetRandom(400.0f,600.0f));
}

Math::Rectangle Fishblue::GetCollision()
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

void Fishblue::OnCollision()
{
    m_sprite.params.pos = Math::Vector2(-140.0f, Random::GetRandom(400.0f, 600.0f));
}

void Fishblue::SetInitialPosition()
{
    m_sprite.params.pos = Math::Vector2(-140.0f, 500.0f);
}