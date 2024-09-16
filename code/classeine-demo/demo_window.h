#pragma once

// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/forward.h>
#include <clsn/ui/dual_layout_container.h>
#include <clsn/ui/main_window.h>

#include <string>

namespace clsn::demo
{
  using namespace clsn::ui;

  class demo_option_container;

  class demo_window : public main_window<dual_layout_container>
  {
    std::shared_ptr<demo_option_container> m_option_container;
    std::shared_ptr<label> m_label;
    std::shared_ptr<dynamic_pane> m_content_pane;

  public:
    demo_window();

    void set_title(const std::string& title);

    auto get_content_pane() -> dynamic_pane&;

  private:
    void init_container();
  };
}