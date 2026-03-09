#pragma once

#include "core/window.hpp"
#include "gfx/ogl_ctx.hpp"
#include "gfx/tex2d.hpp"
#include "glm/glm.hpp"
#include "interfaces/i_aabb.hpp"
#include "game/collision.hpp"

#include <memory>

namespace playground
{
    class player : public interfaces::i_aabb
    {
    public:
        player();
        player(int h, float ms, float msm, glm::vec2 p, float r, glm::vec2 s, glm::vec2 cs, std::unique_ptr<gfx::tex2d> pst);
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

        aabb_collider get_aabb() const override;
    
    
    private:
        int _health {50};
        float _movement_speed {0.05f};
        float _movement_speed_multiplier {1};
        glm::vec2 _position {0, 0};
        float _rotation {0.f};
        glm::vec2 _size {240.0f};
        glm::vec2 _collider_size {240.f, 240.f};
        std::unique_ptr<gfx::tex2d> _player_sprite_texture =  std::make_unique<gfx::tex2d>("img/vex.png");

        aabb_collider invisible_wall {glm::vec2(500, 0), glm::vec2(240.0f)};
        
    };
}