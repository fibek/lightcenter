#ifndef SERIAL_COMMUNICATOR_H_
#define SERIAL_COMMUNICATOR_H_

#include <termios.h>

class Serialcom {
    private:
        struct termios tio;
        int tty_fd;
    public:
        Serialcom();
        void color(char*, char*, char*, char*);
        ~Serialcom();
};

#endif
