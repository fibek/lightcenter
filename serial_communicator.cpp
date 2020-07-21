#include "serial_communicator.h"
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>
#include <iostream>


Serialcom::Serialcom(char *dev) {
    //open communication port
    strcpy(tty_device,dev);
    
    tty_fd=open(tty_device, O_WRONLY | O_NONBLOCK);
    if(!isatty(tty_fd)) {
        std::cerr << "isatty(): " << std::strerror(errno) << std::endl;
        abort();
    }

    if(tcgetattr(tty_fd, &tio)) {
        std::cerr << "tcgetattr: " << errno << std::endl;
        abort();
    }

    tio.c_iflag &=  ~(IGNBRK | BRKINT | ICRNL |
                    INLCR | PARMRK | INPCK | ISTRIP | IXON);
    tio.c_oflag = 0;
    tio.c_cflag &= ~(CSIZE | PARENB);
    tio.c_cflag |= CS8;
    tio.c_lflag &= ~(ECHO | ECHONL | ICANON | IEXTEN | ISIG);
    tio.c_cc[VMIN] = 1;
    tio.c_cc[VTIME] = 0;

    if(cfsetospeed(&tio, B115200)) {
        std::cerr << "cfsetospeed():" << std::strerror(errno) << std::endl;
        abort();
    }

    if(cfsetispeed(&tio, B115200)) {
        std::cerr << "cfsetispeed():" << std::strerror(errno) << std::endl;
        abort();
    }

    if(tcsetattr(tty_fd, TCSAFLUSH, &tio)) {
        std::cerr << "cfsetispeed():" << std::strerror(errno) << std::endl;
        abort();
    }
}

void Serialcom::color(char *set, char *r, char *g, char *b) {
    char *cmd; 
    cmd = new char[15];
    std::strcat(cmd, set);
    std::strcat(cmd, " ");
    std::strcat(cmd, r);
    std::strcat(cmd, " ");
    std::strcat(cmd, g);
    std::strcat(cmd, " ");
    std::strcat(cmd, b);

    std::cout << cmd << std::endl;
    /* tcdrain(tty_fd); */
    /* tcflow(tty_fd, TCOOFF); */
    /* tcflush(tty_fd, TCIOFLUSH); */
    /* tcsendbreak(tty_fd, 0); */
    sleep(1);
    if( write(tty_fd, cmd, strlen(cmd)) < 0 ) 
        std::cerr << "write(): " << std::strerror(errno) << std::endl;
    delete [] cmd;
}


Serialcom::~Serialcom() {
    //close connection with serial device
    close(tty_fd);
}
