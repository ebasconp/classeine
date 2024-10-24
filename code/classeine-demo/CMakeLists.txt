cmake_minimum_required(VERSION 3.27)

project(classeine_demo)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# including directories and dependencies
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../sdl2-cmake-modules")
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_gfx REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS} ${SDL2_GFX_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../classeine-lib)

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

add_executable(classeine_demo
        Main.cpp
        demo_control_container.cpp
        demo_dual_layout_container.cpp
        demo_flow_layout_container.cpp
        demo_xy_layout_container.cpp
        demo_option_container.cpp
        demo_tab_control.cpp
        demo_window.cpp
)

# Linking the library
target_link_libraries(classeine_demo classeine_lib ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES} ${SDL2_GFX_LIBRARIES})