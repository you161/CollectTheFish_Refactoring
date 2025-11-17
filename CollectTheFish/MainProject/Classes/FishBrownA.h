//
//FishBrownA.h
//

#pragma once

#include "../HuEngine.h"

class FishBrownA {
public:
    void Load();
    void Initialize();
    void Update();
    void OnCollision();  
    HE::Math::Rectangle GetCollision();  
    void SetInitialPosition();

private:
    HE::Sprite m_sprite;
    HE::Sprite collision_sprite_;
};