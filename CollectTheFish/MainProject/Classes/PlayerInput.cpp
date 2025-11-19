//
// PlayerInput.cpp
//

#include "PlayerInput.h"

Vector2 PlayerInput::Input()
{
    Vector2 direction;
    if (InputSystem.Keyboard.isPressed.Right)
        direction += Math::Vector2(1, 0);
    if (InputSystem.Keyboard.isPressed.Left)
        direction += Math::Vector2(-1, 0);
    direction.Normalize();

    return direction;
}