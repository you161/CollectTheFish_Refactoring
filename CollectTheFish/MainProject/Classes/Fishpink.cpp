//
//Fishpink.cpp
//

#include "Fishpink.h"

using namespace HE;

void Fishpink::Load()
{
	SpriteObject::Load("fish_pink.png", -50);
}

void Fishpink::Initialize(HE::Math::Vector2 initial)
{
	SpriteObject::Initialize(Vector2(64.0f, 64.0f),Vector2(0.0f,0.0f));
    SetInitialPosition();
}

void Fishpink::Update()
{
    m_sprite.params.pos = m_fishMovement.Movement(m_sprite.params.pos, m_sprite.params.siz, 200.0f, 1,
		Math::Vector2(-80.0f, Random::GetRandom(100.0f, 400.0f)));
}

Math::Rectangle Fishpink::GetCollision()
{
    Math::Rectangle collision;
    collision.x = (long)m_sprite.params.pos.x;
    collision.y = (long)m_sprite.params.pos.y;
    collision.width = (long)m_sprite.params.siz.x;
    collision.height = (long)m_sprite.params.siz.y;

    SpriteObject::SetCollisionSprite(Vector2(collision.width, collision.height), Vector2(collision.x, collision.y));

    return collision;
}

void Fishpink::OnCollision()
{
    SetInitialPosition();
}

void Fishpink::SetInitialPosition()
{
    m_sprite.params.pos = Math::Vector2(-80.0f, 200.0f);
}