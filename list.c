#include "list.h"
#include <stdlib.h>
//loze comment
template <typename T> List<T>::List(){
    kop = 0;
    staart = 0;
}

template<typename T> void List<T>::push_front(T in){
    if (kop == 0) //Maakt een element aan waar de kop en staart naar wijzen als de lijst leeg is
    {
        kop = staart = (struct lijst*) malloc(sizeof(struct lijst));
        kop->next = 0;
        kop->data = in;
    }
    else //Maakt een element aan aan het begin van de lijst als er al wat in de lijst staat en het element nog niet voorkomt
    {
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
    if (kop == 0) //Maakt een element aan waar de kop en staart naar wijzen als de lijst leeg is
    {
        kop = staart = (struct lijst*) malloc(sizeof(lijst));
        kop->next = 0;
        kop->data = in;
    }
    else //Maakt een element aan aan het einde van de lijst als er al wat in de lijst staat en het element nog niet voorkomt
    {
        if (!komtAlVoor(in))
        {
            hulp = (struct lijst*) malloc(sizeof(lijst));
            staart->next = hulp;
            staart = hulp;
            staart->data = in;
        }
    }
}

template <typename T> void List<T>::pop_front(){
if (kop != 0) //Verwijderd de eerste waarde uit de lijst zolang de lijst niet leeg is
    {
        hulp = kop;
        kop = hulp->next;
        free(hulp);
    }
}

template <typename T> void List<T>::pop_back(){
if (kop != 0) //Verwijderd de laatse waarde uit de lijst zolang de lijst niet leeg is
    {
        for (hulp = kop; hulp->next!=staart; hulp=hulp->next){};
        free(hulp->next);
        staart = hulp;
		grootte--;
    }
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

template <typename T> T List<T>::geefKop(){
    if (kop != 0)
        return kop->data;
    else
        return 0;
}

template <typename T> T List<T>::geefPositie(int positie){
    if (positie < 0) positie = 0;
    hulp=kop; //Als de lijst leeg is wordt 0 teruggegeven;
    if (hulp == 0)
            return 0;

    for(int i = 1; i < positie; i++)
    {
        hulp = hulp->next;
        if (hulp == 0)
            return 0;
    }

    return hulp->data;
}
