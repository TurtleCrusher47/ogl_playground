#pragma once

#include "core/window.hpp"
#include "gfx/ogl_ctx.hpp"
#include "gfx/tex2d.hpp"
#include "glm/glm.hpp"

#include <memory>

namespace playground
{
    class player
    {
    public:
        player();
        ~player();
        int get_health() const;
        void set_health(int newHealth);
        int get_movement_speed() const;
        void set_movement_speed(int newMovementSpeed);
        glm::vec2 get_position() const;
        void set_position(glm::vec2 newPosition);
        float get_rotation() const;
        void set_rotation(float newRotation);
        glm::vec2 get_size() const;
        void set_size(glm::vec2 newSize);
        gfx::tex2d* get_spriteptr() const;
        void set_sprite(std::unique_ptr<gfx::tex2d> newSprite);
        void take_damage(int damageTaken);
        void move_player();
        void die();
    
    
    private:
        int _health;
        float _movementSpeed;
        float _movementSpeedMultiplier;
        glm::vec2 _position;
        float _rotation;
        glm::vec2 _size;
        std::unique_ptr<gfx::tex2d> _player_sprite_texture;
    };
}