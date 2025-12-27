#include "game/player.hpp"
#include "gfx/tex2d.hpp"
#include <iostream>

namespace playground
{
    player::player()
    {
        _health = 50;
        _movementSpeed = 10;
        _position = glm::vec2(0, 0);
        player_sprite_texture = std::make_unique<gfx::tex2d>("img/vex.png");
    }
    
    player::~player()
    {
        std::cout << "Player destroyed" << std::endl;
    }
    
    int player::get_health() const
    {
        return _health;
    }
    
    void player::set_health(int newHealth)
    {
        _health = newHealth;
    }
    
    int player::get_movement_speed() const
    {
        return _movementSpeed;
    }
    
    void player::set_movement_speed(int newMovementSpeed)
    {
        _movementSpeed = newMovementSpeed;
    }
    
    glm::vec2 player::get_position() const
    {
        return _position;
    }
    
    void player::set_position(glm::vec2 newPosition)
    {
        _position = newPosition;
        std::cout << "Player position: " << _position.x << ", " << _position.y << std::endl;
    }
    
    void player::take_damage(int damageTaken)
    {
        _health -= damageTaken;
        std::cout << "Damage taken: " << damageTaken << std::endl;
        std::cout << "Remaining health: " << _health << std::endl;
    
        if (_health <= 0)
        {
            die();
        }
        else
        {
            // Regular functionality after taking damage
        }
    }
    
    void player::die()
    {
        // Reset game etc
        std::cout << "Dead" << std::endl;
    }
}
