# classeine

Classeine is a library that should provide all needed tools to make easier
the creation of rich user interfaces in modern C++.

## Features
* Written in modern C++
* Control renderers pluggable
* Built on top of the standard library and:
  * SDL2
  * SDL2_ttf
  * https://github.com/aminosbh/sdl2-cmake-modules
* No exceptions

## Libraries implemented

* **clsn::core** - Core functionality
  * Event management
  * Properties
  * Configuration by sections
  * IEntity polymorphic base class
  
* **clsn::draw** - library providing drawing primitives
  * Color
  * Dimension
  * Font
  * Point
  * Region
* **clsn::ui** - library providing componentable UI controls
  * Control
    * ListContainer<Constraint>
      * HBoxContainer
      * VBoxContainer
    * ClickableControl
      * Button
  * Graphics - abstraction to rendering backend
  * MainWindow
  * UIManager
