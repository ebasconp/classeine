cmake_minimum_required(VERSION 3.27)

project(classeine)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(code/classeine-lib)
add_subdirectory(code/classeine-demo)
        code/classeine-demo/demo_tab_control.cpp
        code/classeine-lib/clsn/ui/tab_page.cpp
        code/classeine-lib/clsn/ui/tab_control.cpp

        code/classeine-lib/clsn/ui/_private/tab_control_view_header_button.cpp
        code/classeine-lib/clsn/ui/_private/tab_control_view_header.cpp
        code/classeine-lib/clsn/ui/_private/tab_control_view.cpp