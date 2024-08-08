#include "light_amatista_ui_theme.h"

#include "clsn/draw/colors.h"

namespace clsn::ui::amatista
{
    auto light_amatista_ui_theme::get_bevel_up_color() const -> color
    {
        return color{0, 92, 155 };
    }

    auto light_amatista_ui_theme::get_bevel_down_color() const -> color
    {
        return color{0, 49, 83 };
    }

    auto light_amatista_ui_theme::get_container_background_color() const -> color
    {
        return colors::make_white();
    }

    auto light_amatista_ui_theme::get_container_foreground_color() const -> color
    {
        return colors::make_black();
    }

    auto light_amatista_ui_theme::get_control_background_color() const -> color
    {
        return color{0xE0, 0xE0, 0xE0};
    }

    auto light_amatista_ui_theme::get_control_foreground_color() const -> color
    {
        return color{0, 49, 83};
    }

    auto light_amatista_ui_theme::get_control_hovered_background_color() const -> color
    {
        return color{0xF0, 0xF0, 0xF0};
    }

    auto light_amatista_ui_theme::get_disabled_background_color() const -> color
    {
        return color{0x60, 0x60, 0x60};
    }

    auto light_amatista_ui_theme::get_disabled_foreground_color() const -> color
    {
        ;return color{160, 160, 160};
    }

    auto light_amatista_ui_theme::get_button_pressed_background_color() const -> color
    {
        return color{192, 192, 192};
    }

}