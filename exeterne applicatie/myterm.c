/*------------------------------------------------------------
 * Simple terminal in C
 * 
 * Arjan J.C. van Gemund (+ few mods by Mark Dufour)
 *------------------------------------------------------------
 */
#define	FALSE		0
#define	TRUE		1

#include <stdio.h>
#include <termios.h>
#include <unistd.h>


/*------------------------------------------------------------
 * console I/O
 *------------------------------------------------------------
 */
struct termios 	savetty;

void	term_initio()
{
	struct termios tty;

        tcgetattr(0, &savetty);
        tcgetattr(0, &tty);
        tty.c_lflag &= ~(ECHO|ECHONL|ICANON|IEXTEN);
        tty.c_cc[VTIME] = 0;
        tty.c_cc[VMIN] = 0;
        tcsetattr(0, TCSADRAIN, &tty);
}

void	term_exitio()
{
	tcsetattr(0, TCSADRAIN, &savetty);
}

void	term_puts(char *s) 
{ 
	fprintf(stderr,"%s",s); 
}

void	term_putchar(char c) 
{ 
	putc(c,stderr); 
}

int	term_getchar_nb() 
{ 
        static unsigned char 	line [2];

	// note: destructive read

        if (read(0,line,1)) {
                return (int) line[0];
        }
        return -1;
}

int	term_getchar() 
{ 
        int    c;

        while ((c = term_getchar_nb()) == -1)
                ;
        return c;
}

/*------------------------------------------------------------
 * serial I/O (8 bits, 1 stopbit, no parity, 9600 baud)
 *------------------------------------------------------------
 */
#include <termios.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>

#define SERIAL_DEVICE 	"/dev/ttyS0"


int fd_RS232;


int rs232_open(void)
{
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

        tty.c_iflag = IGNBRK; /* ignore break condition */
        tty.c_oflag = 0;
        tty.c_lflag = 0;

        tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8; /* 8 bits-per-character */
        tty.c_cflag |= CLOCAL | CREAD; /* Ignore model status + read input */

        cfsetospeed(&tty, B9600); /* set output baud rate */
        cfsetispeed(&tty, B9600); /* set input baud rate */

        tty.c_cc[VMIN]  = 0;
        tty.c_cc[VTIME] = 0;

        tty.c_iflag &= ~(IXON|IXOFF|IXANY);

        result = tcsetattr (fd_RS232, TCSANOW, &tty); /* non-canonical */

        tcflush(fd_RS232, TCIOFLUSH); /* flush I/O buffer */
}


int 	rs232_close(void)
{
  	int 	result;

  	result = close(fd_RS232);
  	assert (result==0);
}


int	rs232_getchar_nb()
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


int 	rs232_getchar()
{
	int 	c;

	while ((c = rs232_getchar_nb()) == -1) 
		;
	return c;
}


int 	rs232_putchar(char c)
{ 
	int result;

	do {
		result = (int) write(fd_RS232, &c, 1);
	} while (result == 0);   

	assert(result == 1);
	return result;
}




/*----------------------------------------------------------------
 * main -- execute terminal
 *----------------------------------------------------------------
 */
int main(void)
{
	char c = 't';

	term_initio();
	rs232_open();

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


    int hoofdcase=0, incase1=0, incase2=0;
    int var=0, i;
    char letters, waarde;
    
    for(; hoofdcase<=2 && hoofdcase>=0; )
    {
      term_puts("\n\nVerkeersplein\n");
      term_puts("\nKies een van de volgende opties:\n");
      term_puts("---------------");
      term_puts("1. Tijden van verkeerslichten aanpassen\n");
      term_puts("2. Nachtstand aan of uit zetten\n");
      term_puts("3. Exit\n");

      hoofdcase=term_getchar();
   
      switch (hoofdcase)
      {
      case 1:
          {
               term_puts("\nTijden van verkeerslichten aanpassen\n");
               term_puts("---------------");
               term_puts("\nWelke van de variabelen wil je aan passen, kies een van de volgende:\n");
               term_puts("1. Het groene licht\n");
               term_puts("2. Het oranje licht\n");
               term_puts("3. Het rode licht\n");
               term_puts("4. De knipper tijd bij nachtsand\n");
               incase1=term_getchar();
                 switch (incase1)
                 {
                        case 1:
                             {
                               term_puts("\nHet groene licht\n");
                               term_puts("---------------");
                               term_puts("\nDe nieuwe tijd\n");
                             
                            letters='g';

                             scanf("%d", &waarde);
                             waarde=term_getchar(); 
                           	rs232_putchar(letters);
                             rs232_putchar(waarde);
                             break;
                             }          
                        case 2:
                             {
                               term_puts("\nHet oranje licht\n");
                               term_puts("---------------");
                               term_puts("\nDe nieuwe tijd\n");
                              
                            letters='o';
                             scanf("%d", &waarde);
                              waarde=term_getchar(); 
                            	rs232_putchar(letters);
                             rs232_putchar(waarde);
                             break;
                             }    
                        case 3:
                             {
                               term_puts("\nHet rood licht\n");
                               term_puts("---------------");
                               term_puts("\nDe nieuwe tijd\n");
                             
                             letters='r';

                             scanf("%d", &waarde);
                              waarde=term_getchar(); 
                            	rs232_putchar(letters);
                             rs232_putchar(waarde);
                             break;
                             }
                        case 4:
                             {
                               term_puts("\nHet groene licht\n");
                               term_puts("---------------");
                               term_puts("\nDe nieuwe knipper tijd bij nachtsand\n");
                             
                             letters='n';
                            
                              waarde=term_getchar(); 
                            	rs232_putchar(letters);
                             rs232_putchar(waarde);                             
                             break;
                             }
                       incase1=0; 
                 }
                 hoofdcase=0;   
                 break;        
          }     
     case 2:
          {
               term_puts("\nNachtstand aan of uit zetten\n");
               term_puts("---------------");
               term_puts("\nWilt u se nachtstand aan of uit zetten, kies een van de volgende 2 opties:\n");
               term_puts("1. Aan zetten\n");
               term_puts("2. Uit zetten\n");

                    incase2=term_getchar();                
                switch (incase2)
                 {
                        case 1:
                             {
                             letters='a';
                            	rs232_putchar(letters);
                             break;
                             }          
                        case 2:
                             {
                             letters='u';
                            	rs232_putchar(letters);
                             break;
                             }   
                  incase2=0;     
                 }   
              hoofdcase=0;
             break;        
          }     
          case 3:
               {
               hoofdcase=3;
                break;           
               }
          }
     waarde=0;
     letters='p';
    }    
   //getchar();     


	term_exitio();
	rs232_close();
	term_puts("\n<exit>\n");
  	exit(0);
}
/*
r = rood
o = tussen groen en rood
g = groen
n = knipperen nachtstand

a = nachtstand aan
u = nachtstand uit
*/

