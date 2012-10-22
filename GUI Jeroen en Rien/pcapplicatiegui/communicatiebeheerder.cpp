#define SERIAL_DEVICE 	"/dev/ttyS0"

#include "communicatiebeheerder.h"
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>


CommunicatieBeheerder::CommunicatieBeheerder() {
    rs232_open();
}

CommunicatieBeheerder::~CommunicatieBeheerder() {
    rs232_close();
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

int CommunicatieBeheerder::rs232_getchar_nb()
{
        int 		result;
        unsigned char 	c;

        result = read(fd_RS232, &c, 1);
        if (result == 0) {
                return -1;
        }
        else {
                assert(result == 1);
                return (int) c;
        }
}

int CommunicatieBeheerder::rs232_getchar()
{
    int c;

    while ((c = rs232_getchar_nb()) == -1)
            ;
    return c;
}
