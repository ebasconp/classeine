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

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(_CLSN_DEBUG_)
    add_compile_options(-Wall -Werror -Wunused-parameter -pedantic)
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
        code/classeine-lib/clsn/ui/dual_container.cpp
        code/classeine-lib/clsn/ui/flow_container.cpp
        code/classeine-lib/clsn/ui/hbox_container.cpp
        code/classeine-lib/clsn/ui/label.cpp
        code/classeine-lib/clsn/ui/radio_button.cpp
        code/classeine-lib/clsn/ui/radio_button_group.cpp
        code/classeine-lib/clsn/ui/toggle_button.cpp
        code/classeine-lib/clsn/ui/toggle_control.cpp
        code/classeine-lib/clsn/ui/UIManager.cpp
        code/classeine-lib/clsn/ui/UISkin.cpp
        code/classeine-lib/clsn/ui/UITheme.cpp
        code/classeine-lib/clsn/ui/vbox_container.cpp
        code/classeine-lib/clsn/ui/window.cpp
        code/classeine-lib/clsn/ui/xy_container.cpp

        code/classeine-lib/clsn/ui/amatista/DarkAmatistaUITheme.cpp
        code/classeine-lib/clsn/ui/amatista/LightAmatistaUITheme.cpp
        code/classeine-lib/clsn/ui/amatista/AmatistaUISkin.cpp
        code/classeine-lib/clsn/ui/amatista/AmatistaUITheme.cpp

        code/classeine-lib/clsn/ui/impl/sdl2/GraphicsSdl2Impl.cpp
        code/classeine-lib/clsn/ui/impl/sdl2/Sdl2FontCache.cpp
        code/classeine-lib/clsn/ui/impl/sdl2/Sdl2Helpers.cpp

        code/classeine-lib/clsn/ui/renderers/BorderRendererHelpers.cpp
        code/classeine-lib/clsn/ui/renderers/ButtonRenderer.cpp
        code/classeine-lib/clsn/ui/renderers/CheckBoxRenderer.cpp
        code/classeine-lib/clsn/ui/renderers/DualContainerRenderer.cpp
        code/classeine-lib/clsn/ui/renderers/FlowContainerRenderer.cpp
        code/classeine-lib/clsn/ui/renderers/HBoxContainerRenderer.cpp
        code/classeine-lib/clsn/ui/renderers/LabelRenderer.cpp
        code/classeine-lib/clsn/ui/renderers/LabelRendererHelpers.cpp
        code/classeine-lib/clsn/ui/renderers/RadioButtonRenderer.cpp
        code/classeine-lib/clsn/ui/renderers/ToggleButtonRenderer.cpp
        code/classeine-lib/clsn/ui/renderers/VBoxContainerRenderer.cpp
        code/classeine-lib/clsn/ui/renderers/XYContainerRenderer.cpp
)

target_include_directories(classeine PUBLIC code/classeine-lib)

target_link_libraries(classeine ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES} ${SDL2_GFX_LIBRARIES})