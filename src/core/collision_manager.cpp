#include "core/collision_manager.hpp"

namespace playground
{
    void playground::collision_manager::add_aabb(interfaces::i_aabb* obj)
    {
        _aabb_objects.push_back(obj);
    }
    
    void playground::collision_manager::remove_aabb(interfaces::i_aabb* obj)
    {
        // Erase is the one actually removing from the list
        // Remove basically searches the vector for the object and puts them at the end
        _aabb_objects.erase(std::remove(_aabb_objects.begin(), _aabb_objects.end(), obj), _aabb_objects.end());
    }
    
    void playground::collision_manager::check_collisions()
    {
        // Using size_t because vector.size() returns size_t
        for (size_t i = 0; i < _aabb_objects.size(); i++)
        {
            for (size_t j = i + 1; j < _aabb_objects.size(); j++)
            {
                // std::cout << "checking collisions" << std::endl;

                if (collision::AABB(*_aabb_objects[i]->get_aabb(), *_aabb_objects[j]->get_aabb()))
                {
                    std::cout << "collide" << std::endl;
                }
            }
        }
    }
}
