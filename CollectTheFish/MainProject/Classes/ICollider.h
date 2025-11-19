#pragma once

#include "../HuEngine.h"

using CollisionRect = HE::Math::Rectangle;

class ICollider{
public:
	virtual ~ICollider() = default;

	virtual CollisionRect GetCollision() = 0;
	virtual void OnCollision() = 0;
};