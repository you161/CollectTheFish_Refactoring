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
	SpriteObject::Initialize(Vector2(84.0f, 63.0f),Vector2(0.0f,0.0f));
    SetInitialPosition();

    // 衝突範囲の表示設定
    collision_sprite_.params.color = HE::Color(255, 0, 0);
    collision_sprite_.params.opacity = 0.0f;              // 透明度
}

void Player::Update()
{
    //上下左右　
    Math::Vector2 direction;

    if (InputSystem.Keyboard.isPressed.Right)
        direction += Math::Vector2(1, 0);
    if (InputSystem.Keyboard.isPressed.Left)
        direction += Math::Vector2(-1, 0);
   
    m_sprite.params.pos.y += 80.0f * Time.deltaTime;
    

    //矢印の長さを1にする
    direction.Normalize();

    auto prev_pos = m_sprite.params.pos;
    m_sprite.params.pos += direction * 100.0f * Time.deltaTime;

    //画面の外に出ないようにする
    m_sprite.params.pos.x = std::clamp(m_sprite.params.pos.x, 0.0f, 1280.0f - 84.0f);
    m_sprite.params.pos.y = std::clamp(m_sprite.params.pos.y, 0.0f, 720.0f - 63.0f);

    if (m_sprite.params.pos.y >= 720.0f - 63.0f) {
        m_sprite.params.pos.y = -64.0f;
    }
}

Math::Rectangle Player::GetCollision()
{
    Math::Rectangle collision;
    collision.x = (long)(m_sprite.params.pos.x);
    collision.y = (long)(m_sprite.params.pos.y);
    collision.width = (long)(m_sprite.params.siz.x);
    collision.height = (long)(m_sprite.params.siz.y);


    // 衝突範囲表示設定
    collision_sprite_.params.pos.x = (float)collision.x;
    collision_sprite_.params.pos.y = (float)collision.y;
    collision_sprite_.params.siz.x = (float)collision.width;
    collision_sprite_.params.siz.y = (float)collision.height;


    return collision;
}


void Player::OnCollision()
{
    SetInitialPosition();
}

void Player::SetInitialPosition()
{
    m_sprite.params.pos = Math::Vector2(
        (RenderingPath->GetLogicalWidth() - m_sprite.params.siz.x) / 2.0f,
        m_sprite.params.pos.y = 0.0f
    );
}





