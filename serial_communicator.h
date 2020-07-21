#ifndef SERIAL_COMMUNICATOR_H_
#define SERIAL_COMMUNICATOR_H_

#include <termios.h>
/* Podczas projektowania gui zrob abstrakcjna klase bazowa */
/* i uzyj jej do wysylania komendy do arduino */
/* ewentualnie: */
/* Dla kazdego radio box wywolaj odpowiadajaca metode */

class Serialcom {
    private:
        struct termios tio;
        int tty_fd;
        char tty_device[256];
    public:
        Serialcom(char *dev);
        void color(char*, char*, char*, char*);
        ~Serialcom();
};

#endif
