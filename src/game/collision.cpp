#include "collision.hpp"

bool collision::AABB(const collider& a, const collider& b)
{
    return
    a.x < b.x + b.width &&
    a.x + a.width > b.x &&
    a.y < b.y + b.height &&
    a.y + a.height > b.y;
}