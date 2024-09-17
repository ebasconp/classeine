# classeine

Classeine is a library that should provide all needed tools to make easier
the creation of rich user interfaces in modern C++.

## Reference docs

http://ebasconp/github.io/classeine

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
    * `entity_wrapper<T>`: Wrapper for any `T`, inheriting from `entity`
  * `factory<T>`: Factory that returns an instance of a base class T when invoked.
  * `lazy<T>`: Object T is constructed the first time this instance is accessed.
  * Simple and tiny string builder
  
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
    * `container`
      *  `mono_container`
        * `padding_control`
      * `layout_container<Layout>`
        * `dual_layout_container` - Container that stores only two elements, one occupying only its preferred size and the other one occupying
          the remaining space
        * `flow_layout_container` - Container where controls are positioned one next to the other according to a left-right-top-bottom ordering
        * `hbox_layout_container` - Container where the controls are rendered horizontally
        * `vbox_layout_container` - Container where the controls are rendered vertically
        * `xy_layout_container` - Container where the controls are placed in specific coordinates in the given region.
    * `dynamic_pane` - Pane able to load and unload dynamically any control
    * `empty_control` - Control that only paints its background. Useful to have a custom renderer.
    * `ui_manager`
      * `ui_skin` - Loadable set of renderers, themes and defaults for the UI controls.
      * `ui_theme` - Set of colors and defaults given a theme. A Skin can have registered several themes but only one current.
        * `amatista_ui_theme` - Set of specific set of colors
          * `light_amatista_ui_theme` - Light theme
          * `dark_amatista_ui_theme` - Dark theme
    * `window`
      * `main_window`
  * `graphics` - abstraction to rendering backend

