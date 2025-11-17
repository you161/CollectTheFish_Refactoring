//
// BG.cpp
//

#include "BG.h"

using namespace HE;

void BG::Load()
{
    SpriteObject::Load("BG_.png",-100);
}

void BG::Initialize()
{
	SpriteObject::Initialize(Math::Vector2(1280.0f, 720.0f), Math::Vector2(0.0f, 0.0f));
}