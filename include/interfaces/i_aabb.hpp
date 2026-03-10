#pragma once

#include "game/aabb_collider.hpp"
#include <iostream>

namespace playground::interfaces
{
    class i_aabb
    {
        public:
            virtual const aabb_collider* get_aabb() const = 0;

        protected:
            virtual ~i_aabb() = default;
    };
}