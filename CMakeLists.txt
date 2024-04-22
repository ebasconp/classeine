cmake_minimum_required(VERSION 3.28)
project(classeine)

set(CMAKE_CXX_STANDARD 23)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(classeine code/classeine-demo/Main.cpp
        code/classeine-lib/clsn/draw/Dimension.cpp
        code/classeine-lib/clsn/core/Panic.h
        code/classeine-lib/clsn/core/Panic.cpp
        code/classeine-lib/clsn/draw/Color.h
        code/classeine-lib/clsn/draw/Color.cpp
        code/classeine-lib/clsn/draw/Colors.h
        code/classeine-lib/clsn/ui/Button.h
        code/classeine-lib/clsn/ui/models/ButtonModel.h
        code/classeine-lib/clsn/ui/renderers/ButtonRenderer.h
        code/classeine-lib/clsn/ui/events/ActionEventManager.h
        code/classeine-lib/clsn/ui/models/WindowModel.h
        code/classeine-lib/clsn/ui/renderers/WindowRenderer.h
        code/classeine-lib/clsn/ui/events/WindowEventManager.h
        code/classeine-lib/clsn/ui/Graphics.h
        code/classeine-lib/clsn/ui/impl/GraphicsImpl.h
        code/classeine-lib/clsn/ui/impl/sdl2/GraphicsSdl2Impl.h
        code/classeine-lib/clsn/ui/impl/sdl2/GraphicsSdl2Impl.cpp)

target_include_directories(classeine PUBLIC code/classeine-lib)

target_link_libraries(classeine ${SDL2_LIBRARIES})