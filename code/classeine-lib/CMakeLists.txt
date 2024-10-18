cmake_minimum_required(VERSION 3.27)

project(classeine_lib)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# including directories and dependencies
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../sdl2-cmake-modules")
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_gfx REQUIRED)

include_directories(. ${SDL2_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS} ${SDL2_GFX_INCLUDE_DIRS})

if (WIN32)
    add_compile_definitions(_CLSN_DEFAULT_FONT_PATH_="c:/windows/fonts/calibri.ttf")
    add_compile_definitions(_CLSN_DEFAULT_BOLD_FONT_PATH_="c:/windows/fonts/calibrib.ttf")
    add_compile_definitions(_CLSN_DEFAULT_ITALIC_FONT_PATH_="c:/windows/fonts/calibrii.ttf")
    add_compile_definitions(_CLSN_DEFAULT_BOLD_ITALIC_FONT_PATH_="c:/windows/fonts/calibriz.ttf")
else ()
    add_compile_definitions(_CLSN_DEFAULT_FONT_PATH_="/usr/share/fonts/opentype/urw-base35/NimbusSans-Regular.otf")
    add_compile_definitions(_CLSN_DEFAULT_BOLD_FONT_PATH_="/usr/share/fonts/opentype/urw-base35/NimbusSans-Bold.otf")
    add_compile_definitions(_CLSN_DEFAULT_ITALIC_FONT_PATH_="/usr/share/fonts/opentype/urw-base35/NimbusSans-Italic.otf")
    add_compile_definitions(_CLSN_DEFAULT_BOLD_ITALIC_FONT_PATH_="/usr/share/fonts/opentype/urw-base35/NimbusSans-BoldItalic.otf")
endif()

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(_CLSN_DEBUG_)
    if (WIN32)
        add_compile_options(/W4 /WX /permissive-)
    else ()
        add_compile_options(-Wall -Wextra -Werror -Wunused-parameter -pedantic)
    endif()
endif()

add_library(classeine_lib
        clsn/core/entity.cpp
        clsn/core/event.cpp
        clsn/core/strings.cpp

        clsn/draw/color.cpp
        clsn/draw/colors.cpp
        clsn/draw/dimension.cpp
        clsn/draw/font.cpp
        clsn/draw/font_info.cpp
        clsn/draw/point.cpp
        clsn/draw/region.cpp

        clsn/ui/button.cpp
        clsn/ui/check_box.cpp
        clsn/ui/captionable_control.cpp
        clsn/ui/clickable_control.cpp
        clsn/ui/content_pane.cpp
        clsn/ui/control.cpp
        clsn/ui/dual_layout_container.cpp
        clsn/ui/dynamic_content_pane.cpp
        clsn/ui/empty_control.cpp
        clsn/ui/flow_layout_container.cpp
        clsn/ui/hbox_layout_container.cpp
        clsn/ui/label.cpp
        clsn/ui/paintable_control.cpp
        clsn/ui/radio_button.cpp
        clsn/ui/tab_page.cpp
        clsn/ui/tab_control.cpp
        clsn/ui/toggle_button.cpp
        clsn/ui/toggle_control_group.cpp
        clsn/ui/toggle_control.cpp
        clsn/ui/ui_manager.cpp
        clsn/ui/ui_skin.cpp
        clsn/ui/ui_theme.cpp
        clsn/ui/vbox_layout_container.cpp
        clsn/ui/window.cpp
        clsn/ui/xy_layout_container.cpp

        clsn/ui/_private/tab_control_view_header_button.cpp
        clsn/ui/_private/tab_control_view_header.cpp
        clsn/ui/_private/tab_control_view.cpp

        clsn/ui/amatista/dark_amatista_ui_theme.cpp
        clsn/ui/amatista/light_amatista_ui_theme.cpp
        clsn/ui/amatista/amatista_ui_skin.cpp
        clsn/ui/amatista/amatista_ui_theme.cpp

        clsn/ui/events/action_event.cpp
        clsn/ui/events/control_event.cpp
        clsn/ui/events/control_resized_event.cpp
        clsn/ui/events/mouse_click_event.cpp
        clsn/ui/events/mouse_moved_event.cpp

        clsn/ui/impl/sdl2/graphics_sdl2_impl.cpp
        clsn/ui/impl/sdl2/sdl2_font_cache.cpp
        clsn/ui/impl/sdl2/sdl2_helpers.cpp

        clsn/ui/layouts/dual_layout.cpp
        clsn/ui/layouts/flow_layout.cpp
        clsn/ui/layouts/hbox_layout.cpp
        clsn/ui/layouts/vbox_layout.cpp
        clsn/ui/layouts/xy_layout.cpp
        clsn/ui/layouts/xy_layout_constraint.cpp

        clsn/ui/painters/background_painter.cpp
        clsn/ui/painters/check_box_painter.cpp
        clsn/ui/painters/border_painter.cpp
        clsn/ui/painters/label_painter.cpp
        clsn/ui/painters/radio_button_painter.cpp

        clsn/ui/renderers/button_renderer.cpp
        clsn/ui/renderers/check_box_renderer.cpp
        clsn/ui/renderers/content_pane_renderer.cpp
        clsn/ui/renderers/customizable_renderer.cpp
        clsn/ui/renderers/empty_control_renderer.cpp
        clsn/ui/renderers/label_renderer.cpp
        clsn/ui/renderers/radio_button_renderer.cpp
        clsn/ui/renderers/toggle_button_renderer.cpp
)