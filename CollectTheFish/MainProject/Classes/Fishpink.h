//
//Fishpink.h
//

#pragma once

#include "../HuEngine.h"
#include"SpriteObject.h"
#include"FishMovement.h"

class Fishpink : public SpriteObject{
public:
    void Load();
    void Initialize(HE::Math::Vector2 initial);
    void Update();
    void OnCollision();  
    HE::Math::Rectangle GetCollision();  
    void SetInitialPosition();

private:
	FishMovement m_fishMovement;
};