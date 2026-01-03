#pragma once

#include "game/aabb_collider.hpp"

namespace playground::interfaces
{
    class i_aabb
    {
        protected:
            virtual aabb_collider get_aabb() const = 0;

            virtual ~i_aabb() = default;
    };
}