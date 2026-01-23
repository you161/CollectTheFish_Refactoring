//
// FishManager.cpp
//

#include "FishManager.h"

using namespace HE;
using namespace Math;

void FishManager::Load(string filename, int order)
{
	SpriteObject::Load(filename, order);
}

void FishManager::Initialize(Vector2 renderSize, Vector2 position)
{
	SpriteObject::Initialize(renderSize, position);
	initial_position = position;
}

void FishManager::Update(float speed , int move)
{
	m_sprite.params.pos = fishMovement_.Movement(m_sprite.params.pos, m_sprite.params.siz, speed, move,
		Vector2(-200.0f, Random::GetRandom(50.0f, 650.0f)));
}

CollisionRect FishManager::GetCollision()
{
	CollisionRect collision;
	collision.x = (long)m_sprite.params.pos.x;
	collision.y = (long)m_sprite.params.pos.y;
	collision.width = (long)m_sprite.params.siz.x;
	collision.height = (long)m_sprite.params.siz.y;

	return collision;
}

void FishManager::OnCollision()
{
	SetPosition();
}

void FishManager::SetPosition()
{
	m_sprite.params.pos = initial_position;
}