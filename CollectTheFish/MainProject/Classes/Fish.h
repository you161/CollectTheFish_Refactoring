#pragma once
#include "../HuEngine.h"
#include "SpriteObject.h"
#include"ICollider.h"
#include "FishParam.h"
#include"FishMovement.h"

class Fish : public SpriteObject,public ICollider
{
public:
    void Load(const FishParam& param);
    void Initialize();
    void Update();

    HE::Math::Rectangle GetCollision();
    void OnCollision();

    std::function<void(int)> CollisionProc;

private:
    FishParam param_;
    FishMovement m_fishMovement;
};