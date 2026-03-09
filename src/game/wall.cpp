#include "game/wall.hpp"

namespace playground
{
    playground::wall::wall()
    {
    }
    
    playground::wall::wall(glm::vec2 vs, glm::vec2 p, glm::vec2 cs)
        : _visual_size(vs), wall_collider{p, cs}
    {
    }
    
    playground::wall::~wall()
    {
    }
    
    aabb_collider wall::get_aabb() const
    {
        return aabb_collider {wall_collider};
    }
}
