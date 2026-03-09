#include "game/player.hpp"
#include "gfx/tex2d.hpp"
#include "core/input_manager.hpp"
#include <iostream>

namespace playground
{
    player::player()
    {
        // _health = 50;
        // _movement_speed = 0.05f;
        // _movement_speed_multiplier = 1;
        // _position = glm::vec2(0, 0);
        // _rotation = 0.f;
        // _size = glm::vec2(240.0f);
        // _collider_size = glm::vec2(240.f);
        // _player_sprite_texture = std::make_unique<gfx::tex2d>("img/vex.png");
    }

    player::player(int h, float ms, float msm, glm::vec2 p, float r, glm::vec2 s, glm::vec2 cs, std::unique_ptr<gfx::tex2d> pst)
        : _health(h), _movement_speed(ms), _movement_speed_multiplier(msm), _position(p), _rotation(r), _size(s), _collider_size(cs), _player_sprite_texture(std::move(pst))
    {
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
        return _movement_speed_multiplier;
    }
    
    void player::set_movement_speed(int new_movement_speed_multipler)
    {
        _movement_speed_multiplier = new_movement_speed_multipler;
    }
    
    glm::vec2 player::get_position() const
    {
        return _position;
    }
    
    void player::set_position(glm::vec2 new_position)
    {
        _position =  new_position;
        std::cout << "Player position: " << _position.x << ", " << _position.y << std::endl;
    }

    float player::get_rotation() const
    {
        return _rotation;
    }

    void player::set_rotation(float new_rotation)
    {
        _rotation = new_rotation;
        std::cout << "Player rotation: " << _rotation << std::endl;
    }

    glm::vec2 player::get_size() const
    {
        return _size;
    }

    void player::set_size(glm::vec2 new_size)
    {
        _size = new_size;
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
    
    void player::take_damage(int damage_taken)
    {
        _health -= damage_taken;
        std::cout << "Damage taken: " << damage_taken << std::endl;
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
        glm::vec2 old_postion = _position;

        // W
        if (core::input_manager::is_key_down(87))
        {
            // std::cout << "W" << std::endl;
            _position.y += _movement_speed * _movement_speed_multiplier;
            if (collision::AABB(get_aabb(), temp_wall.get_aabb()))
            {
                _position = old_postion;
            }
        }
        // A
        if (core::input_manager::is_key_down(65))
        {
            // std::cout << "A" << std::endl;
            _position.x -= _movement_speed * _movement_speed_multiplier;
            if (collision::AABB(get_aabb(), temp_wall.get_aabb()))
            {
                _position = old_postion;
            }
        }
        // S
        if (core::input_manager::is_key_down(83))
        {
            // std::cout << "S" << std::endl;
            _position.y -= _movement_speed * _movement_speed_multiplier;
            if (collision::AABB(get_aabb(), temp_wall.get_aabb()))
            {
                _position = old_postion;
            }
        }
        // D
        if (core::input_manager::is_key_down(68))
        {
            // std::cout << "D" << std::endl;
            _position.x += _movement_speed * _movement_speed_multiplier;
            if (collision::AABB(get_aabb(), temp_wall.get_aabb()))
            {
                _position = old_postion;
            }
        }
    }
    
    void player::die()
    {
        // Reset game etc
        std::cout << "Dead" << std::endl;
    }

    aabb_collider player::get_aabb() const
    {
        // std::cout << "works" << std::endl;
        return aabb_collider { _position, _collider_size };
    }
}
