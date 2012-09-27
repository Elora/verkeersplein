#ifndef WACHTRIJ
#define WACHTRIJ

#include "scenario.h"
#include "list.c"

class WachtrijBeheerder
{
public:
    WachtrijBeheerder(List<Scenario*>*);
    void voegToe(Scenario*);
	bool doorzoekWachtrij(Scenario*);
	void haalEersteUitWachtrij();
	Scenario* geefEersteInWachtrij(Scenario*);

private:
	List<Scenario*> *wachtrij;
};

#endif
