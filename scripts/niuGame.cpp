#include "niuGame.h"

void niuGame::DisplayNewFTXUI() {
    ftxui::ScreenInteractive screen = ftxui::ScreenInteractive::TerminalOutput();

    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    ///                                    Exemplu culori RGB                                           ///
    ///                                                                                                 ///
    ///    Sursa: https://github.com/ArthurSonzogni/FTXUI/blob/main/examples/component/slider_rgb.cpp   ///
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    int red = 128;
    int green = 25;
    int blue = 100;
    ftxui::Component slider_red = ftxui::Slider("Red  :", &red, 0, 255, 1);
    ftxui::Component slider_green = ftxui::Slider("Green:", &green, 0, 255, 1);
    ftxui::Component slider_blue = ftxui::Slider("Blue :", &blue, 0, 255, 1);

    ftxui::Component container = ftxui::Container::Vertical({
        slider_red,
        slider_green,
        slider_blue,
    });

    ftxui::Component renderer = ftxui::Renderer(container, [&] {
        return ftxui::hbox({
                   ftxui::text("pasiunea mea este gatitul"),
                   ftxui::separator(),
                   ftxui::vbox({
                       slider_red->Render(),
                       ftxui::separator(),
                       slider_green->Render(),
                       ftxui::separator(),
                       slider_blue->Render(),
                       ftxui::separator(),
                       ftxui::text("red, green, blue"),
                   }) | ftxui::xflex,
               }) |
               ftxui::border | ftxui::size(ftxui::WIDTH, ftxui::LESS_THAN, 80);
    });
    ///////////////////////////////////////////////////////////////////////////////



    //////////////////////////////////////////////////////////////////////
    ///           Programul se va opri automat dupa 5 secunde           //
    std::thread auto_close([&] {                                //
        std::this_thread::sleep_for(std::chrono::seconds(5));  //
        screen.Exit();                                                  //
    });                                                                 //
    //////////////////////////////////////////////////////////////////////

    screen.Loop(renderer);

    auto_close.join();
}