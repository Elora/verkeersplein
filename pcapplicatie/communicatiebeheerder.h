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
        int rs232_open(void);
        int rs232_close(void);
        int rs232_putchar(char c);

    private:
        int fd_RS232;

};

#endif // COMMUNICATIEBEHEERDER_H
