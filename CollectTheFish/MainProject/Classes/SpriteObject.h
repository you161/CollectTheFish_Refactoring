//
//SpriteObject.h
//

#pragma once

#include "../HuEngine.h"

using namespace HE;
using namespace Math;
using std::string;

class SpriteObject{
public:
    void Load(string filename, int order);
    void Initialize(Vector2 renderSize, Vector2 position);
	void SetCollisionSprite(Vector2 siz,Vector2 pos);
protected:
	Sprite m_sprite;
	Sprite m_collisionSprite;
};