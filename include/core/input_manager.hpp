#pragma once

#include <iostream>
#include <array>
#include <GLFW/glfw3.h>
#include "core/vector2.hpp"

namespace playground::core
{
    class input_manager
    {
        public:
        // Queries
        static bool is_key_down(int key);
        static bool is_mouse_down(int button);

        static vector2double get_mouse_position();

        // GLFW Callbacks
        static void on_key(int key, int scancode, int action, int mods);
        static void on_mouse_button(int button, int action, int mods);
        static void on_cursor_position(double xpos, double ypos);

        private:
        static std::array<bool, GLFW_KEY_LAST + 1> keys;
        static std::array<bool, GLFW_MOUSE_BUTTON_LAST + 1> mouse_buttons;

        static vector2double mouse_position;
    };
}