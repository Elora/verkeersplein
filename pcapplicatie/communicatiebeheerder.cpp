#define SERIAL_DEVICE 	"/dev/ttyS0"

#include "communicatiebeheerder.h"
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>


CommunicatieBeheerder::CommunicatieBeheerder() {

}

int CommunicatieBeheerder::rs232_open(void) {
    char 		*name;
    int 		result;
    struct termios	tty;

    fd_RS232 = open(SERIAL_DEVICE, O_RDWR | O_NOCTTY);
    assert(fd_RS232>=0);

    result = isatty(fd_RS232);
    assert(result == 1);

    name = ttyname(fd_RS232);
    assert(name != 0);

    result = tcgetattr(fd_RS232, &tty);
    assert(result == 0);

    tty.c_iflag = IGNBRK; //ignore break condition
    tty.c_oflag = 0;
    tty.c_lflag = 0;

    tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8; // 8 bits-per-character
    tty.c_cflag |= CLOCAL | CREAD; // Ignore model status + read input

    cfsetospeed(&tty, B9600); // set output baud rate
    cfsetispeed(&tty, B9600); // set input baud rate

    tty.c_cc[VMIN]  = 0;
    tty.c_cc[VTIME] = 0;

    tty.c_iflag &= ~(IXON|IXOFF|IXANY);

    result = tcsetattr (fd_RS232, TCSANOW, &tty); // non-canonical

    tcflush(fd_RS232, TCIOFLUSH); // flush I/O buffer
}

int CommunicatieBeheerder::rs232_close() {
    int result;

    result = close(fd_RS232);
    assert (result==0);
}

int CommunicatieBeheerder::rs232_putchar(char c) {
    int result;

    do {
            result = (int) write(fd_RS232, &c, 1);
    } while (result == 0);

    assert(result == 1);
    return result;
}
