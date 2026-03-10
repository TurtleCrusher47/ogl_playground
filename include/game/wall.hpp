#pragma once

#include "aabb_collider.hpp"
#include "interfaces/i_aabb.hpp"

namespace playground
{
    class wall : public interfaces::i_aabb
    {
        public:
            wall();
            wall(glm::vec2 vs, glm::vec2 p, glm::vec2 cs);
            ~wall();
            const aabb_collider* get_aabb() const override;
            glm::vec2 get_position();


        private:
            glm::vec2 _visual_size {100, 100};
            aabb_collider wall_collider {glm::vec2(100, 100), glm::vec2(100, 100)};
    };
}