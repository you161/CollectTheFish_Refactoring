//
//FishBrown.cpp
//

#include "FishBrown.h"

using namespace HE;

void FishBrown::Load()
{
	SpriteObject::Load("fish_brown.png", -50);;
}

void FishBrown::Initialize()
{
	SpriteObject::Initialize(Vector2(64.0f, 64.0f), Vector2(0.0f, 0.0f));
    SetInitialPosition();
}

void FishBrown::Update()
{
    m_sprite.params.pos = m_fishMovement.Movement(m_sprite.params.pos, m_sprite.params.siz, 400.0f, 1,
		Math::Vector2(-80.0f, Random::GetRandom(50.0f, 680.0f)));
}

Math::Rectangle FishBrown::GetCollision()
{
    Math::Rectangle collision;
    collision.x = (long)m_sprite.params.pos.x;
    collision.y = (long)m_sprite.params.pos.y;
    collision.width = (long)m_sprite.params.siz.x;
    collision.height = (long)m_sprite.params.siz.y;

    SpriteObject::SetCollisionSprite(Vector2(collision.width, collision.height), Vector2(collision.x, collision.y));

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