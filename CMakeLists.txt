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
        code/classeine-lib/clsn/core/Entity.cpp
        code/classeine-lib/clsn/core/Panic.cpp
        code/classeine-lib/clsn/draw/Color.cpp
        code/classeine-lib/clsn/draw/Dimension.cpp
        code/classeine-lib/clsn/draw/Font.cpp
        code/classeine-lib/clsn/draw/FontInfo.cpp
        code/classeine-lib/clsn/draw/Point.cpp
        code/classeine-lib/clsn/draw/Region.cpp
        code/classeine-lib/clsn/ui/UIManager.cpp
        code/classeine-lib/clsn/ui/Button.cpp
        code/classeine-lib/clsn/ui/CheckBox.cpp
        code/classeine-lib/clsn/ui/ClickableControl.cpp
        code/classeine-lib/clsn/ui/Control.cpp
        code/classeine-lib/clsn/ui/HBoxContainer.cpp
        code/classeine-lib/clsn/ui/Label.cpp
        code/classeine-lib/clsn/ui/RadioButton.cpp
        code/classeine-lib/clsn/ui/RadioButtonGroup.cpp
        code/classeine-lib/clsn/ui/ToggleButton.cpp
        code/classeine-lib/clsn/ui/ToggleControl.cpp
        code/classeine-lib/clsn/ui/VBoxContainer.cpp
        code/classeine-lib/clsn/ui/Window.cpp
        code/classeine-lib/clsn/ui/XYContainer.cpp

        code/classeine-lib/clsn/ui/defaults/ButtonDefaults.cpp
        code/classeine-lib/clsn/ui/defaults/CheckBoxDefaults.cpp
        code/classeine-lib/clsn/ui/defaults/HBoxContainerDefaults.cpp
        code/classeine-lib/clsn/ui/defaults/LabelDefaults.cpp
        code/classeine-lib/clsn/ui/defaults/MainWindowDefaults.cpp
        code/classeine-lib/clsn/ui/defaults/ThemeDefaults.cpp
        code/classeine-lib/clsn/ui/defaults/RadioButtonDefaults.cpp
        code/classeine-lib/clsn/ui/defaults/ToggleButtonDefaults.cpp
        code/classeine-lib/clsn/ui/defaults/VBoxContainerDefaults.cpp
        code/classeine-lib/clsn/ui/defaults/XYContainerDefaults.cpp

        code/classeine-lib/clsn/ui/impl/sdl2/GraphicsSdl2Impl.cpp
        code/classeine-lib/clsn/ui/impl/sdl2/Sdl2FontCache.cpp
        code/classeine-lib/clsn/ui/impl/sdl2/Sdl2Helpers.cpp

        code/classeine-lib/clsn/ui/renderers/BorderRenderer.cpp
        code/classeine-lib/clsn/ui/renderers/CheckBoxRenderer.cpp
        code/classeine-lib/clsn/ui/renderers/HBoxContainerRenderer.cpp
        code/classeine-lib/clsn/ui/renderers/LabelRenderer.cpp
        code/classeine-lib/clsn/ui/renderers/RadioButtonRenderer.cpp
        code/classeine-lib/clsn/ui/renderers/VBoxContainerRenderer.cpp
        code/classeine-lib/clsn/ui/renderers/XYContainerRenderer.cpp
)

target_include_directories(classeine PUBLIC code/classeine-lib)

target_link_libraries(classeine ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES} ${SDL2_GFX_LIBRARIES})