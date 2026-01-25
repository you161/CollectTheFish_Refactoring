//
// Player.cpp
//

#include "Player.h"

using namespace HE;

void Player::Load()
{
	SpriteObject::Load("Cat.png", 0);
    RenderingPath->AddSprite(&collision_sprite_, 1);
}


void Player::Initialize()
{
	SpriteObject::Initialize(m_playerData.RenderSize,Vector2(0.0f,0.0f));
    SetPosition();
}

void Player::Update()
{
    m_sprite.params.pos = m_playerMovement.Movement(m_sprite.params.pos,m_playerInput.Input(),
        m_playerData.RenderSize, m_playerData.MovementSpeedX,m_playerData.MovementSpeedY);

    Vector2 move = m_playerInput.Input();
    if (move.x > 0) {
        m_sprite.params.enableMirror();
    }
    else {
        m_sprite.params.disableMirror();
    }

    if (m_sprite.params.pos.y >= 720.0f - m_sprite.params.siz.y) {
        SetPosition();
    }
}

Math::Rectangle Player::GetCollision()
{
    Math::Rectangle collision;
    collision.x = (long)(m_sprite.params.pos.x);
    collision.y = (long)(m_sprite.params.pos.y);
    collision.width = (long)(m_sprite.params.siz.x);
    collision.height = (long)(m_sprite.params.siz.y);

    SpriteObject::SetCollisionSprite(Vector2(collision.width, collision.height), Vector2(collision.x, collision.y));

    return collision;
}

void Player::OnCollision()
{
}

void Player::SetPosition()
{
    m_sprite.params.pos = Math::Vector2(
        (RenderingPath->GetLogicalWidth() - m_sprite.params.siz.x) / 2.0f,
        m_sprite.params.pos.y = 0.0f
    );
}





