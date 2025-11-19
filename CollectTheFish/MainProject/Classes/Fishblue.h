//
//Fishblue.h
//

#pragma once

#include "../HuEngine.h"
#include"SpriteObject.h"
#include"FishMovement.h"

class Fishblue : public SpriteObject{
public:
    void Load();
    void Initialize();
    void Update();
    void OnCollision();  
    HE::Math::Rectangle GetCollision();  
    void SetInitialPosition();

private:
    FishMovement m_fishMovement;
};