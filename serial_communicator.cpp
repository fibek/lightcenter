#include "serial_communicator.h"
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>
#include <iostream>

extern char tty_device[30];

Serialcom::Serialcom() {
    
    tty_fd=open(tty_device, O_WRONLY );

    if(!isatty(tty_fd)) {
        std::cerr << "isatty(): " << std::strerror(errno) << std::endl;
        abort();
    }

    if(tcgetattr(tty_fd, &tio)) {
        std::cerr << "tcgetattr: " << std::strerror(errno) << std::endl;
        abort();
    }

    /* --configure-- */
    tio.c_cc[VMIN] = 1;
    tio.c_cc[VTIME] = 5;
    tio.c_iflag = 0;
    tio.c_oflag = 0;
    tio.c_cflag = CS8 | CREAD | CLOCAL;
    tio.c_lflag = 0;

    if(cfsetospeed(&tio, B115200)) {
        std::cerr << "cfsetospeed():" << std::strerror(errno) << std::endl;
        abort();
    }

    if(cfsetispeed(&tio, B115200)) {
        std::cerr << "cfsetispeed():" << std::strerror(errno) << std::endl;
        abort();
    }

    if(tcsetattr(tty_fd, TCSANOW, &tio)) {
        std::cerr << "tcsetattr():" << std::strerror(errno) << std::endl;
        abort();
    }
}

void Serialcom::color(char *set, char *r, char *g, char *b) {
    sleep(1);
    char *cmd;
    char *buf;
    cmd = new char[15];
    std::strcat(cmd, ".");
    std::strcat(cmd, set);
    std::strcat(cmd, ".");
    std::strcat(cmd, r);
    std::strcat(cmd, ".");
    std::strcat(cmd, g);
    std::strcat(cmd, ".");
    std::strcat(cmd, b);
    std::strcat(cmd, ".");

    std::cout << cmd << std::endl;
    if( tcdrain(tty_fd) < 0 )
        std::cerr << "tcdrain(): " << std::strerror(errno) << std::endl;
    if( write(tty_fd, cmd, strlen(cmd)) < 0 ) 
        std::cerr << "write(): " << std::strerror(errno) << std::endl;


    delete [] cmd;
}


Serialcom::~Serialcom() {
    //close connection with serial device
    close(tty_fd);
}

