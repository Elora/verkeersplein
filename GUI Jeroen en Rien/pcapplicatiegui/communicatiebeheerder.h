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
        int rs232_OpenVerbinding(void);
        int rs232_VerbreekVerbinding(void);
        int rs232_SchrijfChar(char c);
        int rs232_KrijgChar();

    private:
        int rs232_LeesSerial();
        int fd_RS232;

};

#endif // COMMUNICATIEBEHEERDER_H
