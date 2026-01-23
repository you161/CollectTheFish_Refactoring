//
//FishManager.h
//

#pragma once
#include "../HuEngine.h"
#include"SpriteObject.h"
#include"ICollider.h"
#include"FishMovement.h"

using namespace HE;
using namespace Math;
using std::string;

class FishManager : public SpriteObject, public ICollider {
public:
	void Load(string filename, int order);
	void Initialize(Vector2 renderSize, Vector2 position);
	void Update(float speed, int move);
	void SetPosition();
	CollisionRect GetCollision()override;
	void OnCollision() override;

protected:
private:
	FishMovement fishMovement_;
	Vector2 initial_position;
};