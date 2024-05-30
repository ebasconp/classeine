#include <iostream>

#include "clsn/core/Panic.h"

#include "clsn/ui/Button.h"
//#include "clsn/ui/HBoxContainer.h"
#include "clsn/ui/MainWindow.h"
//#include "clsn/ui/VBoxContainer.h"
//
//#include "clsn/core/EventListenerList.h"
//#include "clsn/core/Property.h"
//#include "clsn/core/ValueChangedEvent.h"

#include "clsn/ui/renderers/NullRenderer.h"

#include <memory>

int main()
{
    using namespace clsn::core;
    using namespace clsn::ui;
    using namespace clsn::ui::renderers;

    MainWindow<Button> mw;
    mw().setText("Hello world");

    //    mw.getControl().getController().addActionListener([](auto& )
    //    {
    //        static int n = 0;
    //        std::cout << "CLICKED " << (++n) << " times" << std::endl;
    //    });
    //
    //    mw.getControl().getModel().setText("Click me");

    //
    //    auto textArea= mw.makeAndAdd<TextArea>(BorderLayoutConsts::CENTER);
    //
    //    auto button = mw.makeAndAdd<Button>(BorderLayoutConsts::NORTH);
    //    button->setText("Click me");
    //    button->addActionListener([&](auto& )
    //    {
    //        static int n = 0;
    //        textArea->setText(textArea.getText() + "\n" + (++n) + " clicks" );
    //    });
    //

//    MainWindow<VBoxContainer> mw;
//    auto b1 = mw.getControl().getModel().createAndAdd<Button>();
//    b1->getModel().setText("Click me");
//
//    auto b2 = mw.getControl().getModel().createAndAdd<Button>();
//    b2->getModel().setText("Click me again");
//
//    auto b3 = mw.getControl().getModel().createAndAdd<Button>();
//    b3->getModel().setText("Click me three");
//
//    auto b4 = mw.getControl().getModel().createAndAdd<Button>();
//    b4->getModel().setText("Click me");
//
//    auto hbc = mw.getControl().getModel().createAndAdd<HBoxContainer>();
//    auto b5 = hbc->getModel().createAndAdd<Button>();
//    auto b6 = hbc->getModel().createAndAdd<Button>();
//
//    b5->getModel().setText("B5");
//    b6->getModel().setText("B6");
//
//    b5->getController().addActionListener([](auto& e)
//    {
//        std::cout << "B5" << std::endl; }
//    );
//    b6->getController().addActionListener([](auto& ) { std::cout << "B6" << std::endl; });
//
//    static int n = 0;
//
//    b1->getController().addActionListener(
//        [&b4](auto& e)
//        {
//            b4->getModel().setText(
//                std::string{"Click me (" + std::to_string(++n) + ")"});
//        });
//
//    b2->getController().addActionListener(
//        [&b4, &b1](auto& e)
//        {
//            b4->getModel().setText(
//                std::string{"Click me (" + std::to_string(--n) + ")"});
//
//            b1->setVisible(!b1->isVisible());
//        });
//
//    b3->getController().addActionListener(
//        [&b4](auto& e)
//        {
//            n = 0;
//            b4->getModel().setText(
//                std::string{"Click me (0)"});
//        });
//
//    b3->setEnabled(false);
//
//    b4->getController().addActionListener([&b4](auto& e)
//    {
//        auto color = b4->getForegroundColor();
//        if (color == Colors::BLACK)
//            color = Colors::RED;
//        else if (color == Colors::RED)
//            color = Colors::GREEN;
//        else if (color == Colors::GREEN)
//            color = Colors::BLUE;
//        else
//            color = Colors::BLACK;
//
//        b4->setForegroundColor(color);
//    });

    mw.setVisible(true);

    return 0;
}