#pragma once

#include "core/vector2.hpp"


class Player {
public:
    Player();
    ~Player();
    int GetHealth() const;
    void SetHealth(int newHealth);
    int GetMovementSpeed() const;
    void SetMovementSpeed(int newMovementSpeed);
    vector2 GetPosition() const;
    void SetPosition(vector2 newPosition);
    void TakeDamage(int damageTaken);
    void Die();


private:
    int _health;
    int _movementSpeed;
    vector2 _position;
};