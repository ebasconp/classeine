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
  * `Entity` polymorphic base class: Adds some memory profiling tools
    * `EntityWrapper<T>`: Wrapper for any `T`, inheriting from `Entity`
  * `Lazy<T>`: Object T is constructed the first time this instance is accessed.
  
* **clsn::draw** - library providing drawing primitives
  * `Color`
  * `Dimension`
  * `Font`
  * `Point`
  * `Region`
  
* **clsn::ui** - library providing componentable UI controls
  * `Control`
    * `ClickableControl`
      * `Button` 
      * `ToggleControl`
        * `CheckBox` 
        * `ToggleButton`
    * `Label` 
    * `ListContainer<Constraint>`
      * `HBoxContainer`
      * `VBoxContainer`
    * `UIManager`
    * `Window`
      * `MainWindow`
  * `Graphics` - abstraction to rendering backend

