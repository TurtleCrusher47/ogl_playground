#pragma once

#include <string>
#include "core/vector2.hpp"

struct GLFWwindow;

namespace playground::core
{
    // GLFW Window wrapper, handles initialization of GLFW
    class window
    {
    public:
        window(const std::string& title, const unsigned int width,
            const unsigned int height);
        ~window();

        void update();

        inline GLFWwindow* get_internal() const
        {
            return handle;
        }

        inline const unsigned int get_width() const
        {
            return width;
        }

        inline const unsigned int get_height() const
        {
            return height;
        }

        // Input helpers
        bool is_key_pressed(int key) const;
        bool is_mouse_button_pressed(int button) const;
        // vector2double get_mouse_position() const;
        

    private:
        GLFWwindow* handle;

        std::string title;
        unsigned int width, height;
        
        static void on_resize(GLFWwindow* window, int width, int height);
        static void on_close(GLFWwindow* window);
        static void on_key_press(GLFWwindow* window, int key, int scancode, int action, int mods);
        static void on_mouse_button(GLFWwindow* window, int button, int action, int mods);
        static void on_cursor_position(GLFWwindow* window, double xpos, double ypos);
    };
}