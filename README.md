# classeine

Classeine is a library that should provide all needed tools to make easier
the creation of rich user interfaces in modern C++.

## Features
* Written in modern C++
* Control renderers pluggable
* Built on top of the standard library and:
  * SDL2
  * SDL2_ttf
  * SDL2_gfx
  * https://github.com/aminosbh/sdl2-cmake-modules
* No exceptions

## Libraries implemented

* **clsn::core** - Core functionality
  * Event management
  * Properties
  * configuration by sections
  * `entity` polymorphic base class: Adds some memory profiling tools
    * `EntityWrapper<T>`: Wrapper for any `T`, inheriting from `entity`
  * `Factory<T>`: Factory that returns an instance of a base class T when invoked.
  * `Lazy<T>`: Object T is constructed the first time this instance is accessed.
  
* **clsn::draw** - library providing drawing primitives
  * `color`
  * `dimension`
  * `font`
  * `point`
  * `region`
  
* **clsn::ui** - library providing componentable UI controls
  * `Control`
    * `ClickableControl`
      * `Button` 
      * `ToggleControl`
        * `CheckBox` 
        * `RadioButton`
        * `ToggleButton`
    * `Label` 
    * `ListContainer<Constraint>`
      * `DualContainer` - Container that stores only two elements, one occupying only its preferred size and the other one occupying
        the remaining space
      * `FlowContainer` - Container where controls are positioned one next to the other according to a left-right-top-bottom ordering
      * `HBoxContainer` - Container where the controls are rendered horizontally
      * `VBoxContainer` - Container where the controls are rendered vertically
      * `XYContainer` - Container where the controls are placed in specific coordinates in the given region.
    * `UIManager`
      * `UISkin` - Loadable set of renderers, themes and defaults for the UI controls.
      * `UITheme` - Set of colors and defaults given a theme. A Skin can have registered several themes but only one current.
        * `AmatistaUITheme` - Set of specific set of colors
          * `LightAmatistaUITheme` - Light theme
          * `DarkAmatistaUITheme` - Dark theme
    * `Window`
      * `MainWindow`
  * `Graphics` - abstraction to rendering backend

