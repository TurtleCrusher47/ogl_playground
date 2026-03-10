#pragma once
#include <vector>

#include "interfaces/i_aabb.hpp"
#include "game/collision.hpp"

namespace playground
{
    class collision_manager
    {
    public:
        void add_aabb(interfaces::i_aabb* obj);
        void remove_aabb(interfaces::i_aabb* obj);

        void check_collisions();

    private:
        std::vector<interfaces::i_aabb*> _aabb_objects;
    };
}