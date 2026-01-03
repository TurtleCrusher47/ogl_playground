#include "game/player.hpp"
#include "gfx/tex2d.hpp"
#include "core/input_manager.hpp"
#include <iostream>

namespace playground
{
    player::player()
    {
        _health = 50;
        _movementSpeed = 0.05f;
        _movementSpeedMultiplier = 1;
        _position = glm::vec2(0, 0);
        _rotation = 0.f;
        _size = glm::vec2(240.0f);
        _player_sprite_texture = std::make_unique<gfx::tex2d>("img/vex.png");
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
        return _movementSpeedMultiplier;
    }
    
    void player::set_movement_speed(int newMovementSpeedMultiplier)
    {
        _movementSpeedMultiplier = newMovementSpeedMultiplier;
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

    float player::get_rotation() const
    {
        return _rotation;
    }

    void player::set_rotation(float newRotation)
    {
        _rotation = newRotation;
        std::cout << "Player rotation: " << _rotation << std::endl;
    }

    glm::vec2 player::get_size() const
    {
        return _size;
    }

    void player::set_size(glm::vec2 newSize)
    {
        _size = newSize;
        std::cout << "Player size: " << _size.x << ", " << _size.y << std::endl;
    }

    gfx::tex2d* player::get_spriteptr() const
    {
        if (_player_sprite_texture.get())
        {
            // std::cout << "Render player" << std::endl;
            return _player_sprite_texture.get();
        }
        else
        {
            std::cout << "No texture" << std::endl;
            return 0;
        }
    }

    void player::set_sprite(std::unique_ptr<gfx::tex2d> newSpritePtr)
    {
        _player_sprite_texture = std::move(newSpritePtr);
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

    void player::move_player()
    {
        // W
        if (core::input_manager::is_key_down(87))
        {
            // std::cout << "W" << std::endl;
            _position.y += _movementSpeed * _movementSpeedMultiplier;
            get_aabb();
        }
        // A
        if (core::input_manager::is_key_down(65))
        {
            // std::cout << "A" << std::endl;
            _position.x -= _movementSpeed * _movementSpeedMultiplier;
        }
        // S
        if (core::input_manager::is_key_down(83))
        {
            // std::cout << "S" << std::endl;
            _position.y -= _movementSpeed * _movementSpeedMultiplier;
        }
        // D
        if (core::input_manager::is_key_down(68))
        {
            // std::cout << "D" << std::endl;
            _position.x += _movementSpeed * _movementSpeedMultiplier;
        }
    }
    
    void player::die()
    {
        // Reset game etc
        std::cout << "Dead" << std::endl;
    }

    aabb_collider player::get_aabb() const
    {
        std::cout << "works" << std::endl;
        return aabb_collider { _position, _collider_size };
    }
}
