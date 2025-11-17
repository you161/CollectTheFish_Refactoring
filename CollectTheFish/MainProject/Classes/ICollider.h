#pragma once

#include "../HEToolKit/DirectXTK/SimpleMath.h"

class ICollider {
public:
	virtual ~ICollider() = default;
	virtual DirectX::SimpleMath::Rectangle GetCollider() = 0;
	virtual void OnCollision() = 0;
};