#include "MainWindowDefaults.h"

#include "clsn/draw/Dimension.h"

namespace clsn::ui::defaults::MainWindowDefaults
{
    using namespace clsn::draw;

    void populateDefaults(clsn::ui::UIManagerDefaults& defaults)
    {
        defaults.set("MainWindow", "minimumSize", Dimension(100, 100));
        defaults.set("MainWindow", "size", Dimension(800, 600));
    }
}