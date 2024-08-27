cmake_minimum_required(VERSION 3.27)

project(classeine)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# using FindSDL2* files from https://github.com/aminosbh/sdl2-cmake-modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../sdl2-cmake-modules")

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_gfx REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL_TTF_INCLUDE_DIRS} ${SDL2_GFX_INCLUDE_DIRS})

if (WIN32)
    add_compile_definitions(_CLSN_DEFAULT_FONT_PATH_="c:/windows/fonts/calibri.ttf")
else ()
    add_compile_definitions(_CLSN_DEFAULT_FONT_PATH_="/usr/share/fonts/opentype/urw-base35/NimbusSans-Regular.otf")
endif()

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(_CLSN_DEBUG_)
    if (WIN32)
        add_compile_options(/W4 /WX /permissive-)
    else ()
        add_compile_options(-Wall -Wextra -Werror -Wunused-parameter -pedantic)
    endif()
endif()

add_executable(classeine code/classeine-demo/Main.cpp
        code/classeine-lib/clsn/core/entity.cpp
        code/classeine-lib/clsn/core/strings.cpp

        code/classeine-lib/clsn/draw/color.cpp
        code/classeine-lib/clsn/draw/colors.cpp
        code/classeine-lib/clsn/draw/dimension.cpp
        code/classeine-lib/clsn/draw/font.cpp
        code/classeine-lib/clsn/draw/font_info.cpp
        code/classeine-lib/clsn/draw/point.cpp
        code/classeine-lib/clsn/draw/region.cpp

        code/classeine-lib/clsn/ui/button.cpp
        code/classeine-lib/clsn/ui/check_box.cpp
        code/classeine-lib/clsn/ui/clickable_control.cpp
        code/classeine-lib/clsn/ui/control.cpp
        code/classeine-lib/clsn/ui/dual_layout_container.cpp
        code/classeine-lib/clsn/ui/flow_layout_container.cpp
        code/classeine-lib/clsn/ui/hbox_layout_container.cpp
        code/classeine-lib/clsn/ui/label.cpp
        code/classeine-lib/clsn/ui/radio_button.cpp
        code/classeine-lib/clsn/ui/radio_button_group.cpp
        code/classeine-lib/clsn/ui/toggle_button.cpp
        code/classeine-lib/clsn/ui/toggle_control.cpp
        code/classeine-lib/clsn/ui/ui_manager.cpp
        code/classeine-lib/clsn/ui/ui_skin.cpp
        code/classeine-lib/clsn/ui/ui_theme.cpp
        code/classeine-lib/clsn/ui/vbox_layout_container.cpp
        code/classeine-lib/clsn/ui/window.cpp
        code/classeine-lib/clsn/ui/xy_layout_container.cpp

        code/classeine-lib/clsn/ui/amatista/dark_amatista_ui_theme.cpp
        code/classeine-lib/clsn/ui/amatista/light_amatista_ui_theme.cpp
        code/classeine-lib/clsn/ui/amatista/amatista_ui_skin.cpp
        code/classeine-lib/clsn/ui/amatista/amatista_ui_theme.cpp

        code/classeine-lib/clsn/ui/impl/sdl2/graphics_sdl2_impl.cpp
        code/classeine-lib/clsn/ui/impl/sdl2/sdl2_font_cache.cpp
        code/classeine-lib/clsn/ui/impl/sdl2/sdl2_helpers.cpp

        code/classeine-lib/clsn/ui/layouts/dual_layout.cpp
        code/classeine-lib/clsn/ui/layouts/flow_layout.cpp
        code/classeine-lib/clsn/ui/layouts/hbox_layout.cpp
        code/classeine-lib/clsn/ui/layouts/vbox_layout.cpp
        code/classeine-lib/clsn/ui/layouts/xy_layout.cpp

        code/classeine-lib/clsn/ui/painters/background_painter.cpp
        code/classeine-lib/clsn/ui/painters/check_box_painter.cpp
        code/classeine-lib/clsn/ui/painters/border_painter.cpp
        code/classeine-lib/clsn/ui/painters/label_painter.cpp
        code/classeine-lib/clsn/ui/painters/radio_button_painter.cpp

        code/classeine-lib/clsn/ui/renderers/button_renderer.cpp
        code/classeine-lib/clsn/ui/renderers/check_box_renderer.cpp
        code/classeine-lib/clsn/ui/renderers/customizable_renderer.cpp
        code/classeine-lib/clsn/ui/renderers/label_renderer.cpp
        code/classeine-lib/clsn/ui/renderers/radio_button_renderer.cpp
        code/classeine-lib/clsn/ui/renderers/toggle_button_renderer.cpp
        code/classeine-lib/clsn/ui/mono_container.h
)

target_include_directories(classeine PUBLIC code/classeine-lib)

target_link_libraries(classeine ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES} ${SDL2_GFX_LIBRARIES})
