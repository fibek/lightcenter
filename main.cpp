#include "gui.h"
#include <cstring>

char tty_device[30]; //extern char tty_device[30] in file "serial_communicator.cpp"

int main(int argc, char **argv) {
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.lightcenter");
    Gui GUI;
    std::strcpy(tty_device, "/dev/ttyUSB0");
    return app->run(GUI);
}

