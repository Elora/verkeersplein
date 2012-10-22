#ifndef COMMUNICATIEBEHEERDER_H
#define COMMUNICATIEBEHEERDER_H

/*------------------------------------------------------------
 * serial I/O (8 bits, 1 stopbit, no parity, 9600 baud)
 *------------------------------------------------------------
 */

class CommunicatieBeheerder
{
    public:
        CommunicatieBeheerder();
        ~CommunicatieBeheerder();
        int rs232_open(void);
        int rs232_close(void);
        int rs232_putchar(char c);
        int rs232_getchar();

    private:
        int rs232_getchar_nb();
        int fd_RS232;

};

#endif // COMMUNICATIEBEHEERDER_H
