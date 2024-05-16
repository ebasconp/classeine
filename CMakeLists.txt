cmake_minimum_required(VERSION 3.28)
project(classeine)

set(CMAKE_CXX_STANDARD 23)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(classeine code/classeine-demo/Main.cpp
        code/classeine-lib/clsn/core/Panic.cpp
        code/classeine-lib/clsn/draw/Color.cpp
        code/classeine-lib/clsn/draw/Dimension.cpp
        code/classeine-lib/clsn/draw/Point.cpp
        code/classeine-lib/clsn/draw/Region.cpp
        code/classeine-lib/clsn/ui/UIManager.cpp
        code/classeine-lib/clsn/ui/defaults/ButtonDefaults.cpp
        code/classeine-lib/clsn/ui/defaults/ThemeDefaults.cpp
        code/classeine-lib/clsn/ui/impl/sdl2/GraphicsSdl2Impl.cpp
        code/classeine-lib/clsn/ui/renderers/BorderRenderer.cpp
)

target_include_directories(classeine PUBLIC code/classeine-lib)

target_link_libraries(classeine ${SDL2_LIBRARIES})