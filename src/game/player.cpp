#include "game/player.hpp"
#include <iostream>

Player::Player()
{
    _health = 50;
    _movementSpeed = 10;
    _position = vector2(0, 0);
}

Player::~Player()
{
    std::cout << "Player destroyed" << std::endl;
}

int Player::GetHealth() const
{
    return _health;
}

void Player::SetHealth(int newHealth)
{
    _health = newHealth;
}

int Player::GetMovementSpeed() const
{
    return _movementSpeed;
}

void Player::SetMovementSpeed(int newMovementSpeed)
{
    _movementSpeed = newMovementSpeed;
}

vector2 Player::GetPosition() const
{
    return _position;
}

void Player::SetPosition(vector2 newPosition)
{
    _position = newPosition;
    std::cout << "Player position: " << _position.x << ", " << _position.y << std::endl;
}

void Player::TakeDamage(int damageTaken)
{
    _health -= damageTaken;
    std::cout << "Damage taken: " << damageTaken << std::endl;
    std::cout << "Remaining health: " << _health << std::endl;

    if (_health <= 0)
    {
        Die();
    }
    else
    {
        // Regular functionality after taking damage
    }
}

void Player::Die()
{
    // Reset game etc
    std::cout << "Dead" << std::endl;
}
