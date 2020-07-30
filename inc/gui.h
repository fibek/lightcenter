#ifndef LIGHTCENTER_GRAPHICALUSERINTERFACE_H_
#define LIGHTCENTER_GRAPHICALUSERINTERFACE_H_

#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/radiobutton.h>
#include <gtkmm/box.h>
#include <gtkmm/separator.h>
#include <serial_communicator.h>

class Gui : public Gtk::Window {
	protected:
                /* widegts */
		Gtk::Button b_apply;
		Gtk::RadioButton mode1,mode2;
                Gtk::Box main_box,top, bot;
                Gtk::Separator sep1;
                
                /* signal handlers */
		void on_button_clicked();

	public:
		Gui();
                /* Serialcom &device; //pass it to colorpicker class */
		virtual ~Gui();

};

#endif
