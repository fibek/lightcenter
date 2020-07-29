#ifndef LIGHTCENTER_COLORPICKER_H_
#define LIGHTCENTER_COLORPICKER_H_

#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/entry.h>
#include <gtkmm/button.h>

class Colorpick : public Gtk::Window {
    protected:
        /* widgets */
        Gtk::Box main_box,top,bot;
        Gtk::Entry p,r,g,b;
        Gtk::Button set;

        /* signal handlers */
        void on_button_clicked();
    public:
        Colorpick();
        /* Serialcom &device; */
        virtual ~Colorpick();
};

#endif
