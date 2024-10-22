#pragma once

// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/Forward.h>
#include <clsn/ui/DualLayoutContainer.h>
#include <clsn/ui/MainWindow.h>

#include <string>

namespace clsn::demo
{
  using namespace clsn::ui;

  class demo_option_container;

  class demo_window : public MainWindow<DualLayoutContainer>
  {
    std::shared_ptr<demo_option_container> m_option_container;
    std::shared_ptr<Label> m_label;
    std::shared_ptr<DynamicContentPane> m_content_pane;

  public:
    demo_window();

    void set_title(const std::string& title);

    auto get_content_pane() -> DynamicContentPane&;

  private:
    void init_container();
  };
}