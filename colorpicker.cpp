#include "colorpicker.h"

Colorpick::Colorpick() : set("set"), 
                         main_box(Gtk::ORIENTATION_VERTICAL),
                         top(Gtk::ORIENTATION_VERTICAL, 10),
                         bot(Gtk::ORIENTATION_VERTICAL, 10) {
  set_default_size(200,200);
  set_title("lightcenter - choose color");
  set_border_width(30);
  add(main_box);
  main_box.pack_start(top);
  main_box.pack_start(bot);
  top.set_border_width(15);
  bot.set_border_width(15);

  p.set_text("0");
  r.set_text("255");
  g.set_text("255");
  b.set_text("255");
  top.pack_start(p);
  top.pack_start(r);
  top.pack_start(g);
  top.pack_start(b);

  bot.pack_start(set);

  show_all_children();
}

void Colorpick::on_button_clicked() {
   //     
}

Colorpick::~Colorpick() {

}


