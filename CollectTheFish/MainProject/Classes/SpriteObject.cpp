//
// SpriteObject.cpp
//

#include "SpriteObject.h"

using namespace HE;
using namespace Math;

/// <param name="filename">画像指定</param>
/// <param name="order">画像表示の優先順位</param>
void SpriteObject::Load(string filename, int order)
{
	m_sprite = Sprite(filename);
	RenderingPath->AddSprite(&m_sprite, order);
	RenderingPath->AddSprite(&m_collisionSprite, order + 1);
}

/// <param name="renderSize">画像サイズ</param>
/// <param name="position">初期座標</param>
void SpriteObject::Initialize(Vector2 renderSize, Vector2 position)
{
	m_sprite.params.siz = renderSize;
    m_sprite.params.pos = position;
    m_sprite.params.enableDrawRect(Rectf(0, 0, m_sprite.params.siz.x, m_sprite.params.siz.y));

	m_collisionSprite.params.color = HE::Color(0, 0, 255);
	m_collisionSprite.params.opacity = 0.0f;
}

void SpriteObject::SetCollisionSprite(Vector2 siz,Vector2 pos)
{
	m_collisionSprite.params.siz = siz;
	m_collisionSprite.params.pos = pos;
}