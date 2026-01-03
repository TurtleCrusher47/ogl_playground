#include "collision.hpp"

bool collision::AABB(const aabb_collider& a, const aabb_collider& b)
{
    return
    a.position.x < b.position.x + b.size.x &&
    a.position.x + a.size.x > b.position.x &&
    a.position.y < b.position.y + b.size.y &&
    a.position.y + a.size.y > b.position.y;
}
