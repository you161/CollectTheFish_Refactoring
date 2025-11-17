//
//player.h
//

#pragma once

#include "../HuEngine.h"
#include"SpriteObject.h"

class Player : public SpriteObject{
public:
    void Load();
    void Initialize();
    void Update();

    HE::Math::Rectangle GetCollision();
    void OnCollision();

    HE::Math::Vector3 GetPosition() const { return m_sprite.params.pos; }
    void SetInitialPosition();  

  
    
private:
    HE::Sprite collision_sprite_;
};
