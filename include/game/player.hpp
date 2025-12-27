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
        void take_damage(int damageTaken);
        void die();
    
    
    private:
        int _health;
        int _movementSpeed;
        glm::vec2 _position;
        std::unique_ptr<gfx::tex2d> player_sprite_texture;
    };
}