#pragma once

#include "aabb_collider.hpp"

class collision
{
public:
    static bool AABB(const aabb_collider& a, const aabb_collider& b);
};