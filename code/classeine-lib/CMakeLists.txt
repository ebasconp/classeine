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
        clsn/core/Entity.cpp
        clsn/core/Event.cpp
        clsn/core/Strings.cpp

        clsn/draw/color.cpp
        clsn/draw/Colors.cpp
        clsn/draw/Dimension.cpp
        clsn/draw/Font.cpp
        clsn/draw/FontInfo.cpp
        clsn/draw/Point.cpp
        clsn/draw/Region.cpp

        clsn/ui/Button.cpp
        clsn/ui/CheckBox.cpp
        clsn/ui/CaptionableControl.cpp
        clsn/ui/ClickableControl.cpp
        clsn/ui/ContentPane.cpp
        clsn/ui/Control.cpp
        clsn/ui/DualLayoutContainer.cpp
        clsn/ui/DynamicContentPane.cpp
        clsn/ui/EmptyControl.cpp
        clsn/ui/FlowLayoutContainer.cpp
        clsn/ui/HBoxLayoutContainer.cpp
        clsn/ui/Label.cpp
        clsn/ui/PaintableControl.cpp
        clsn/ui/RadioButton.cpp
        clsn/ui/RadioButtonGroup.cpp
        clsn/ui/ToggleButton.cpp
        clsn/ui/ToggleControl.cpp
        clsn/ui/UIManager.cpp
        clsn/ui/UISkin.cpp
        clsn/ui/UITheme.cpp
        clsn/ui/VBoxLayoutContainer.cpp
        clsn/ui/Window.cpp
        clsn/ui/XYLayoutContainer.cpp

        clsn/ui/amatista/DarkAmatistaUITheme.cpp
        clsn/ui/amatista/LightAmatistaUITheme.cpp
        clsn/ui/amatista/AmatistaUISkin.cpp
        clsn/ui/amatista/AmatistaUITheme.cpp

        clsn/ui/events/ActionEvent.cpp
        clsn/ui/events/ControlEvent.cpp
        clsn/ui/events/ControlResizedEvent.cpp
        clsn/ui/events/MouseClickEvent.cpp
        clsn/ui/events/MouseMovedEvent.cpp

        clsn/ui/impl/sdl2/GraphicsSDL2Impl.cpp
        clsn/ui/impl/sdl2/SDL2FontCache.cpp
        clsn/ui/impl/sdl2/SDL2Helpers.cpp

        clsn/ui/layouts/DualLayout.cpp
        clsn/ui/layouts/FlowLayout.cpp
        clsn/ui/layouts/HBoxLayout.cpp
        clsn/ui/layouts/VBoxLayout.cpp
        clsn/ui/layouts/XYLayout.cpp
        clsn/ui/layouts/XYLayoutConstraint.cpp

        clsn/ui/painters/BackgroundPainter.cpp
        clsn/ui/painters/CheckBoxPainter.cpp
        clsn/ui/painters/BorderPainter.cpp
        clsn/ui/painters/LabelPainter.cpp
        clsn/ui/painters/RadioButtonPainter.cpp

        clsn/ui/renderers/ButtonRenderer.cpp
        clsn/ui/renderers/CheckBoxRenderer.cpp
        clsn/ui/renderers/ContentPaneRenderer.cpp
        clsn/ui/renderers/CustomizableRenderer.cpp
        clsn/ui/renderers/EmptyControlRenderer.cpp
        clsn/ui/renderers/LabelRenderer.cpp
        clsn/ui/renderers/RadioButtonRenderer.cpp
        clsn/ui/renderers/ToggleButtonRenderer.cpp
)