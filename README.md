# classeine

Classeine is a library designed to provide all the necessary tools for creating full-featured and portable applications built on top of SDL2 in modern C++.

Please note that it is currently in an early stage of development.

## Features
* Written in modern C++
* UI Control renderers pluggable with multi-theme support
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
  * `Color`
  * `Dimension`
  * `Font`
  * `Point`
  * `Region`
  
* **clsn::ui** - library providing componentable UI controls
  * `Control`
    * `EmptyControl` - Control that does nothing. Useful to have a custom renderer. 
    * `PaintableControl` - Control with background, foreground and Font 
      * `CaptionableControl`
        * `ClickableControl`
          * `Button` 
          * `ToggleControl`
            * `CheckBox` 
            * `RadioButton`
            * `ToggleButton`
        * `Label` 
        * `Window`
          * `MainWindow`
      * `Container`
        * `ConstrainedContainer<Constraint>` - Container that stores controls with its constraints
          * `LayoutContainer<Layout>`
            * `DualLayoutContainer` - Container that stores only two elements, one occupying only its preferred size and the other one occupying
              the remaining space
            * `FlowLayoutContainer` - Container where controls are positioned one next to the other according to a left-right-top-bottom ordering
            * `HBoxLayoutContainer` - Container where the controls are rendered horizontally
            * `VBoxLayoutContainer` - Container where the controls are rendered vertically
            * `XYLayoutContainer` - Container where the controls are placed in specific coordinates in the given Region.
      * `ContentPane` - Abstract class that handles Layout and events for specific Control containers
        * `DynamicContentPane` - Content pane able to load and unload dynamically any Control
        * `StaticContentPane` - Content pane with its child content already bound in compile time
          * `PaddingControl` - Control with a border with variable size
  * `Graphics` - abstraction to rendering backend
  * `UIManager`
  * `UISkin` - Loadable set of renderers, themes and defaults for the UI controls.
  * `UITheme` - Set of Colors and defaults given a theme. A Skin can have registered several themes but only one current.
    * `AmatistaUITheme` - Set of specific set of Colors
      * `LightAmatistaUITheme` - Light theme
      * `DarkAmatistaUITheme` - Dark theme

## Supported Platforms
  * Linux
  * Windows

## GitHub 

http://www.github.com/ebasconp/classeine

