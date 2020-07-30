#include <gui.h>
#include <iostream>
#include <gtkmm/colorchooser.h>
#include <colorpicker.h>

Gui::Gui() : b_apply("Apply"), 
             mode1("Pick color"),
             mode2("Pywal"), 
             main_box(Gtk::ORIENTATION_VERTICAL),
             top(Gtk::ORIENTATION_VERTICAL, 10),
             bot(Gtk::ORIENTATION_VERTICAL, 10) 
{
    //--window--
    set_default_size(145,171);
    set_title("lightcenter");
    set_border_width(30);
    add(main_box);
    main_box.pack_start(top);
    main_box.pack_start(sep1);
    main_box.pack_start(bot);
    top.set_border_width(15);
    bot.set_border_width(15);

    //--apply-button--
    b_apply.signal_clicked().connect( sigc::mem_fun(*this, &Gui::on_button_clicked) );
    bot.pack_start(b_apply);

    //--radiobuttons--
    mode2.join_group(mode1);
    mode1.set_active();
    top.pack_start(mode1);
    top.pack_start(mode2);

    show_all_children();
}

void Gui::on_button_clicked() {
    std::cout << "Mode updated" << std::endl
              << "Mode1: " << mode1.get_active() << std::endl
              << "Mode2: " << mode2.get_active() << std::endl;
    if(mode1.get_active()) {
        auto picker = Gtk::Application::create("org.gtkmm.lightcenter.picker");
        Colorpick colorpicker;
        picker->run(colorpicker);
    }
}

Gui::~Gui() {

}



