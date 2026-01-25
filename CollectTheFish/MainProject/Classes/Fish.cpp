#include "Fish.h"
using namespace HE;

void Fish::Load(const FishParam& param)
{
    param_ = param;
    SpriteObject::Load(param_.sprite.c_str(), 1);
}

void Fish::Initialize()
{
    SpriteObject::Initialize(
        param_.drawSize,
        Vector2(0.0f, 0.0f)
    );
    m_sprite.params.pos = param_.spawnPos;

    if (param_.direction < 0) {
        m_sprite.params.enableMirror();
    }
}

void Fish::Update()
{
    m_sprite.params.pos =
        m_fishMovement.Movement(
            m_sprite.params.pos,
            m_sprite.params.siz,
            param_.speed,
            param_.direction,
        Vector2(
            param_.spawnPos.x,
            Random::GetRandom(100.0f, 400.0f))
        );
}

Math::Rectangle Fish::GetCollision()
{
    Math::Rectangle collision;
    collision.x = (long)m_sprite.params.pos.x;
    collision.y = (long)m_sprite.params.pos.y;
    collision.width = (long)m_sprite.params.siz.x;
    collision.height = (long)m_sprite.params.siz.y;

    SetCollisionSprite(
        Vector2(collision.width, collision.height),
        Vector2(collision.x, collision.y)
    );
    return collision;
}

void Fish::OnCollision()
{
    if (CollisionProc)
        CollisionProc(param_.score);

    if (param_.resetOnHit)
        m_sprite.params.pos = Vector2(param_.spawnPos.x,
            Random::GetRandom(param_.spawnPos.y - 100.0f, param_.spawnPos.y + 100.0f));
}