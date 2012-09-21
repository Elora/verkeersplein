#ifndef WACHTRIJ
#define WACHTRIJ

#include "scenario.h"
#include "list.c"

class Wachtrij
{
public:
    Wachtrij();
    void voegToe(Scenario*);
	bool doorzoekWachtrij(Scenario*);
	void haalUitWachtrij(Scenario*);
	Scenario* geefEersteInWachtrij(Scenario*);

private:
	List<Scenario*> rij;
};

#endif
