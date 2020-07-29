#include "colorpicker.h"
#include <cstring>
#include "serial_communicator.h"

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

  p.set_max_length(1);
  r.set_max_length(3);
  g.set_max_length(3);
  b.set_max_length(3);
  p.set_text("0");
  r.set_text("255");
  g.set_text("255");
  b.set_text("255");
  top.pack_start(p);
  top.pack_start(r);
  top.pack_start(g);
  top.pack_start(b);

  set.signal_clicked().connect( sigc::mem_fun(*this, &Colorpick::on_button_clicked) );
  bot.pack_start(set);

  show_all_children();
}

void Colorpick::on_button_clicked() {
    Serialcom clr_send;
    std::string sp, sr, sg, sb;
    sp = p.get_text();
    sr = r.get_text();
    sg = g.get_text();
    sb = b.get_text();
    /* clr_send.color(sp.c_str(), sr.c_str(), sg.c_str(), sb.c_str()); */ 
    clr_send.color(&sp[0], &sr[0], &sg[0], &sb[0]);
}

Colorpick::~Colorpick() {

}


