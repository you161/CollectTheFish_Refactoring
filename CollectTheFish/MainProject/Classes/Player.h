//
//player.h
//

#pragma once

#include "../HuEngine.h"
#include"SpriteObject.h"
#include"ICollider.h"
#include"PlayerData.h"
#include"PlayerInput.h"
#include"PlayerMovement.h"

class Player : public SpriteObject, public ICollider {
public:
    std::function<void()> CollisionProc;
    void Load();
    void Initialize();
    void Update();

    HE::Math::Rectangle GetCollision();
    void OnCollision();

    HE::Math::Vector3 GetPosition() const { return m_sprite.params.pos; }
    void SetPosition();

private:
    Sprite collision_sprite_;
    PlayerData m_playerData;
    PlayerInput m_playerInput;
    PlayerMovement m_playerMovement;
};
