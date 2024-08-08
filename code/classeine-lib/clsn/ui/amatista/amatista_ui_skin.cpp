#include "clsn/ui/amatista/amatista_ui_skin.h"

#include "clsn/ui/amatista/dark_amatista_ui_theme.h"
#include "clsn/ui/amatista/light_amatista_ui_theme.h"

#include "clsn/ui/button.h"
#include "clsn/ui/check_box.h"
#include "clsn/ui/flow_container.h"
#include "clsn/ui/hbox_container.h"
#include "clsn/ui/label.h"
#include "clsn/ui/radio_button.h"
#include "clsn/ui/toggle_button.h"
#include "clsn/ui/vbox_container.h"
#include "clsn/ui/xy_container.h"

#include "clsn/ui/renderers/button_renderer.h"
#include "clsn/ui/renderers/check_box_renderer.h"
#include "clsn/ui/renderers/dual_container_renderer.h"
#include "clsn/ui/renderers/flow_container_renderer.h"
#include "clsn/ui/renderers/hbox_container_renderer.h"
#include "clsn/ui/renderers/label_renderer.h"
#include "clsn/ui/renderers/radio_button_renderer.h"
#include "clsn/ui/renderers/toggle_button_renderer.h"
#include "clsn/ui/renderers/vbox_container_renderer.h"
#include "clsn/ui/renderers/xy_container_renderer.h"

namespace
{
    using namespace clsn::ui;

    void load_renderers(amatista::amatista_ui_skin& skin)
    {
        skin.make_renderer_and_add<button, button_renderer>();
        skin.make_renderer_and_add<check_box, check_box_renderer>();
        skin.make_renderer_and_add<dual_container, dual_container_renderer>();
        skin.make_renderer_and_add<flow_container, flow_container_renderer>();
        skin.make_renderer_and_add<hbox_container, hbox_container_renderer>();
        skin.make_renderer_and_add<label, label_renderer>();
        skin.make_renderer_and_add<radio_button, radio_button_renderer>();
        skin.make_renderer_and_add<toggle_button, toggle_button_renderer>();
        skin.make_renderer_and_add<vbox_container, vbox_container_renderer>();
        skin.make_renderer_and_add<xy_container, xy_container_renderer>();
    }

    void load_themes(amatista::amatista_ui_skin& skin)
    {
        skin.make_theme_and_add<amatista::light_amatista_ui_theme>("light");
        skin.make_theme_and_add<amatista::dark_amatista_ui_theme>("dark");

        skin.install_theme_by_name("dark");
    }
}

namespace clsn::ui::amatista
{
    amatista_ui_skin::amatista_ui_skin()
    {
        using namespace clsn::ui;
        using namespace clsn::ui::renderers;

        load_renderers(*this);
        load_themes(*this);
    }
}