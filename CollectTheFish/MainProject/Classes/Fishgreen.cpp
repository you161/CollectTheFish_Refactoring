//
//Fishgreen.cpp
//

#include "Fishgreen.h"

using namespace HE;

void Fishgreen::Load()
{
	SpriteObject::Load("fish_green.png", -50);
}

void Fishgreen::Initialize()
{
	SpriteObject::Initialize(Vector2(64.0f, 64.0f), Vector2(0.0f, 0.0f));
    SetInitialPosition();
}

void Fishgreen::Update()
{
    m_sprite.params.pos = m_fishMovement.Movement(m_sprite.params.pos, m_sprite.params.siz, 80.0f, 1,
		Math::Vector2(-80.0f, Random::GetRandom(300.0f, 680.0f)));
}

Math::Rectangle Fishgreen::GetCollision()
{
    Math::Rectangle collision;
    collision.x = (long)m_sprite.params.pos.x;
    collision.y = (long)m_sprite.params.pos.y;
    collision.width = (long)m_sprite.params.siz.x;
    collision.height = (long)m_sprite.params.siz.y;

    SpriteObject::SetCollisionSprite(Vector2(collision.width, collision.height), Vector2(collision.x, collision.y));

    return collision;
}

void Fishgreen::OnCollision()
{
    m_sprite.params.pos = Math::Vector2(-80.0f, Random::GetRandom(300.0f, 660.0f));
}

void Fishgreen::SetInitialPosition()
{
    m_sprite.params.pos = Math::Vector2(-80.0f, 600.0f);
}