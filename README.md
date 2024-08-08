# classeine

Classeine is a library that should provide all needed tools to make easier
the creation of rich user interfaces in modern C++.

## Features
* Written in modern C++
* control renderers pluggable
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
  * `control`
    * `clickable_control`
      * `button` 
      * `toggle_control`
        * `check_box` 
        * `radio_button`
        * `toggle_button`
    * `label` 
    * `list_container<Constraint>`
      * `dual_container` - Container that stores only two elements, one occupying only its preferred size and the other one occupying
        the remaining space
      * `flow_container` - Container where controls are positioned one next to the other according to a left-right-top-bottom ordering
      * `hbox_container` - Container where the controls are rendered horizontally
      * `vbox_container` - Container where the controls are rendered vertically
      * `xy_container` - Container where the controls are placed in specific coordinates in the given region.
    * `UIManager`
      * `UISkin` - Loadable set of renderers, themes and defaults for the UI controls.
      * `UITheme` - Set of colors and defaults given a theme. A Skin can have registered several themes but only one current.
        * `AmatistaUITheme` - Set of specific set of colors
          * `LightAmatistaUITheme` - Light theme
          * `DarkAmatistaUITheme` - Dark theme
    * `window`
      * `main_window`
  * `graphics` - abstraction to rendering backend

