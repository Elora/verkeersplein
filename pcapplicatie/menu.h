#ifndef MENU_H
#define MENU_H

#include "communicatiebeheerder.h"

class Menu
{
    public:
        Menu(CommunicatieBeheerder*);
        int toonHoofdMenu();
        void nachtStandAanpassen();
        void tijdenAanpassen();
        void pasKnippertijdAan();
        void pasRoodAan();
        void pasOranjeAan();
        void pasGroenAan();

    private:
        CommunicatieBeheerder* communicatiebeheerder;


};

#endif // MENU_H
