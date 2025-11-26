#include "core/input_manager.hpp"

namespace playground::core
{
    std::array<bool, GLFW_KEY_LAST + 1> input_manager::keys{};
    std::array<bool, GLFW_MOUSE_BUTTON_LAST + 1> input_manager::mouse_buttons{};
    vector2double input_manager::mouse_position{};

    // Queries
    bool input_manager::is_key_down(int key)
    {
        if (key < 0 || key > GLFW_KEY_LAST) return false;

        return keys[key];
    }

    bool input_manager::is_mouse_down(int button)
    {
        if (button < 0 || button > GLFW_MOUSE_BUTTON_LAST) return false;

        return mouse_buttons[button];
    }

    vector2double input_manager::get_mouse_position()
    {
        return mouse_position;
    }

    // Callbacks
    void input_manager::on_key(int key, int scancode, int action, int mods)
    {
        if (key < 0 || key > GLFW_KEY_LAST) return;

        if (action == GLFW_PRESS)
            keys[key] = true;
        else if (action == GLFW_RELEASE)
            keys[key] = false;
    }

    void input_manager::on_mouse_button(int button, int action, int mods)
    {
        if (button < 0 || button > GLFW_MOUSE_BUTTON_LAST) return;

        if (action == GLFW_PRESS)
            mouse_buttons[button] = true;
        else if (action == GLFW_RELEASE)
            mouse_buttons[button] = false;
    }

    void input_manager::on_cursor_position(double xpos, double ypos)
    {
        std::cout << "xpos: " << xpos << ", ypos: " << ypos << std::endl;
        mouse_position = { xpos, ypos };
    }
}