//
//Fishblue.cpp
//

#include "Fishblue.h"

using namespace HE;

void Fishblue::Load()
{
	SpriteObject::Load("fish_blue.png", -50);
}

void Fishblue::Initialize()
{
	SpriteObject::Initialize(Vector2(128.0f, 128.0f), Vector2(0.0f, 0.0f));
    SetInitialPosition();
}

void Fishblue::Update()
{
    m_sprite.params.pos = m_fishMovement.Movement(m_sprite.params.pos, m_sprite.params.siz, 150.0f, 1,
        Vector2(-140.0f, Random::GetRandom(400.0f, 600.0f)));
}

Math::Rectangle Fishblue::GetCollision()
{
    Math::Rectangle collision;
    collision.x = (long)m_sprite.params.pos.x;
    collision.y = (long)m_sprite.params.pos.y;
    collision.width = (long)m_sprite.params.siz.x;
    collision.height = (long)m_sprite.params.siz.y;

    SpriteObject::SetCollisionSprite(Vector2(collision.width, collision.height), Vector2(collision.x, collision.y));

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