# classeine

Classeine is a library that should provide all needed tools to make easier
the creation of rich user interfaces in modern C++.

## Features
* Written in modern C++
* MVC heavily used
* Control models/renderers and controllers pluggable through templates
* Built on top of the standard library and:
  * SDL2
  * SDL2_ttf
  * https://github.com/aminosbh/sdl2-cmake-modules
* No exceptions

## Libraries implemented

* **clsn::draw** - library providing drawing primitives
  * Color
  * Dimension
  * Font
  * Point
  * Region
* **clsn::ui** - library providing componentable UI controls
  * Button
  * MainWindow
  * UIManager

