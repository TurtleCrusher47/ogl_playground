#include "core/window.hpp"

#include "core/app.hpp"
#include "GLFW/glfw3.h"

#include <iostream>
#include <cassert>

namespace playground::core
{
    window::window(const std::string& title, const unsigned int width,
        const unsigned int height)
        : title(title)
        , width(width)
        , height(height)
    {
        int glfw_init_result = glfwInit();
        assert(glfw_init_result);

        glfwSetErrorCallback(
            [](int error, const char* desc)
            {
                std::cout << "GLFW error: (" << error << "): {" << desc << "}"
                          << std::endl;
            });

        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        handle
            = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        assert(handle);

        // Store a pointer to the wrapper such that we can
        // access it later on in callbacks
        glfwSetWindowUserPointer(handle, this);

        // Handle callbacks
        glfwSetWindowSizeCallback(handle, on_resize);
        glfwSetWindowCloseCallback(handle, on_close);

        // Input callbacks
        glfwSetKeyCallback(handle, on_key_press);
        glfwSetMouseButtonCallback(handle, on_mouse_button);
        glfwSetCursorPosCallback(handle, on_cursor_position);
    }

    window::~window()
    {
        glfwDestroyWindow(handle);
    }

    void window::update()
    {
        glfwPollEvents();
    }

    bool window::is_key_pressed(int key) const
    {
        return glfwGetKey(handle, key) == GLFW_PRESS;
    }

    bool window::is_mouse_button_pressed(int button) const
    {
        return glfwGetMouseButton(handle, button) == GLFW_PRESS;
    }

    // vector2double window::get_mouse_position() const
    // {
    //     vector2double position;
    //     glfwGetCursorPos(handle, position.x, position.y);
    //     return position;
    // }

    playground::core::window* get_wrapper(GLFWwindow*& window)
    {
        return reinterpret_cast<playground::core::window*>(
            glfwGetWindowUserPointer(window));
    }

    void window::on_resize(GLFWwindow* window, int width, int height)
    {
        auto wrapper = get_wrapper(window);

        wrapper->width = width;
        wrapper->height = height;
    }

    void window::on_close(GLFWwindow* window)
    {
        app::get().close();
    }

    void window::on_key_press(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        {
            on_close(window);
        }

        if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
        {
            std::cout << "SPACE PRESSED" << std::endl;
        }
    }

    void window::on_mouse_button(GLFWwindow* window, int button, int action, int mods)
    {

    }

    void window::on_cursor_position(GLFWwindow* window, double xpos, double ypos)
    {

    }
}