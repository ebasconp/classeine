# classeine

Classeine is a library designed to provide all the necessary tools for creating full-featured and portable applications built on top of SDL2 in modern C++.

Please note that it is currently in an early stage of development.

## Features
* Written in modern C++
* UI control renderers pluggable with multi-theme support
* Built on top of the standard library and:
  * SDL2
  * SDL2_ttf
  * SDL2_gfx
  * https://github.com/aminosbh/sdl2-cmake-modules
* No exceptions
* No manual memory management (through extensive usage of smart pointers and RAII)

## Libraries implemented

* **clsn::core** - Core functionality
  * Event management
  * Properties
  * configuration by sections
  * `Entity` polymorphic base class: Adds some memory profiling tools
    * `EntityWrapper<T>`: Wrapper for any `T`, inheriting from `Entity`
  * `Factory<T>`: Factory that returns an instance of a base class T when invoked.
  * `Lazy<T>`: Object T is constructed the first time this instance is accessed.
  * Simple and tiny string builder
  
* **clsn::draw** - library providing drawing primitives
  * `color`
  * `dimension`
  * `font`
  * `point`
  * `region`
  
* **clsn::ui** - library providing componentable UI controls
  * `control`
    * `empty_control` - Control that does nothing. Useful to have a custom renderer. 
    * `paintable_control` - Control with background, foreground and font 
      * `captionable_control`
        * `clickable_control`
          * `button` 
          * `toggle_control`
            * `check_box` 
            * `radio_button`
            * `toggle_button`
        * `label` 
        * `window`
          * `main_window`
      * `container`
        * `constrained_container<Constraint>` - Container that stores controls with its constraints
          * `layout_container<Layout>`
            * `dual_layout_container` - Container that stores only two elements, one occupying only its preferred size and the other one occupying
              the remaining space
            * `flow_layout_container` - Container where controls are positioned one next to the other according to a left-right-top-bottom ordering
            * `hbox_layout_container` - Container where the controls are rendered horizontally
            * `vbox_layout_container` - Container where the controls are rendered vertically
            * `xy_layout_container` - Container where the controls are placed in specific coordinates in the given region.
      * `content_pane` - Abstract class that handles layout and events for specific control containers
        * `dynamic_content_pane` - Content pane able to load and unload dynamically any control
        * `static_content_pane` - Content pane with its child content already bound in compile time
          * `padding_control` - Control with a border with variable size
  * `graphics` - abstraction to rendering backend
  * `ui_manager`
  * `ui_skin` - Loadable set of renderers, themes and defaults for the UI controls.
  * `ui_theme` - Set of colors and defaults given a theme. A Skin can have registered several themes but only one current.
    * `amatista_ui_theme` - Set of specific set of colors
      * `light_amatista_ui_theme` - Light theme
      * `dark_amatista_ui_theme` - Dark theme

## Supported Platforms
  * Linux
  * Windows

## GitHub 

http://www.github.com/ebasconp/classeine

