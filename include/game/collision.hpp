#pragma once

#include "collider.hpp"

class collision
{
public:
    static bool AABB(const collider& a, const collider& b);
};