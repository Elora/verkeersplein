#ifndef LISTC
#define LISTC

#include "list.h"
#include <stdlib.h>
//Dit is de volgende loze comment2
template <typename T> List<T>::List(){
    kop = 0;
    staart = 0;
}

template<typename T> void List<T>::push_front(T in){
    //Maakt een element aan waar de kop en staart naar wijzen als de lijst leeg is
		if (kop == 0) 
    {
        kop = staart = (struct lijst*) malloc(sizeof(struct lijst));
        kop->next = 0;
        kop->data = in;
    }
    else 
    {
		//Maakt een element aan aan het begin van de lijst als er al wat in de lijst staat 
		//en het element nog niet voorkomt
        if (!komtAlVoor(in))
        {
            hulp = (struct lijst*) malloc(sizeof(lijst));
            hulp->next = kop;
            kop = hulp;
            kop->data = in;
        }
    }
}

template <typename T> void List<T>::push_back(T in){
    //Maakt een element aan waar de kop en staart naar wijzen als de lijst leeg is
		if (kop == 0) 
    {
        kop = staart = (struct lijst*) malloc(sizeof(lijst));
        kop->next = 0;
        kop->data = in;
    }
    //Maakt een element aan aan het einde van de lijst als er al wat in de lijst staat 
		//en het element nog niet voorkomt
		else 
    {
        if (!komtAlVoor(in))
        {
            hulp = (struct lijst*) malloc(sizeof(lijst));
            staart->next = hulp;
            staart = hulp;
            staart->data = in;
			staart->next = 0;
        }
    }
}

template <typename T> void List<T>::pop_front(){
//Verwijderd de eerste waarde uit de lijst zolang de lijst niet leeg is
if (kop != 0) 
    {
        hulp = kop;
        kop = hulp->next;
        free(hulp);
    }
}

template <typename T> void List<T>::pop_back(){
//Verwijderd de laatse waarde uit de lijst zolang de lijst niet leeg is
if (kop != 0) 
    {
        for (hulp = kop; hulp->next!=staart; hulp=hulp->next){};
        free(hulp->next);
        staart = hulp;
		staart->next = 0;
    }
}

template <typename T> void List<T>::leegLijst(){
	while(kop!=0) pop_front();
}

template <typename T> bool List<T>::komtAlVoor(T in){
// Kijkt of de waarde al in de lijst voorkomt
    for (hulp = kop; hulp != 0; hulp = hulp->next)
    {
        if (hulp->data == in)
            return true;
    }
    return false;
}

template <typename T> T List<T>::krijgKop(){
//Geeft de kop zolang de lijst gevuld is
    if (kop != 0)
        return kop->data;
    else
        return 0;
}

template <typename T> void List<T>::haalUitLijst(T uit){
//Verwijderd de het opgegeven object uit de lijst
	struct lijst* hulp2;
	//Kijken of de lijst leeg is
    if (kop != 0)
    {
			//Kijken of het om de kop gaat
        if (kop->data == uit)
        {
            hulp = kop->next;
            free(kop);
            kop = hulp;
        }
        else
        {
					//loop de hele lijst door
            for (hulp = kop; hulp != staart; )
            {
								//test of het volgende object verwijderd moet worden
                if (hulp->next->data == uit)
                {
                    hulp2 = hulp->next->next;
                    free(hulp->next);
                    hulp->next = hulp2;
										if (hulp2 == 0)
											staart = hulp;
                    hulp = staart;
                }
                else hulp = hulp->next;
            }
        }
    }
}

template <typename T> T List<T>::geefPositie(int positie){
    if (positie < 0) positie = 0;
    hulp=kop;

		//Als de lijst leeg is wordt 0 teruggegeven;
    if (hulp == 0)
            return 0;
		
		//Als de lijst gevuld is wordt de hele lijst doorgelopen totdat het element is gevonden
		//of totdat de hele lijst is doorgelopen zonder iets te vinden
    for(int i = 1; i < positie; i++)
    {
        hulp = hulp->next;
        if (hulp == 0)
            return 0;
    }

    return hulp->data;
}

#endif
