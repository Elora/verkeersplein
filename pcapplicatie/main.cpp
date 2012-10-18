#define	FALSE		0
#define	TRUE		1
#define SERIAL_DEVICE 	"/dev/ttyS0"

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>
#include <time.h>
#include "menu.h"
#include "communicatiebeheerder.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(void)
{
    CommunicatieBeheerder communicatiebeheerder;
    Menu menu(&communicatiebeheerder);
    communicatiebeheerder.rs232_open();
    int uitvoeren = 1;

    while(uitvoeren == 1) {
        uitvoeren = menu.toonHoofdMenu();

    }

    communicatiebeheerder.rs232_close();
}
