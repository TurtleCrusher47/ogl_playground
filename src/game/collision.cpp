#include "collision.hpp"

bool collision::AABB(const aabb_collider& a, const aabb_collider& b)
{
    return
    a.x < b.x + b.width &&
    a.x + a.width > b.x &&
    a.y < b.y + b.height &&
    a.y + a.height > b.y;
}
