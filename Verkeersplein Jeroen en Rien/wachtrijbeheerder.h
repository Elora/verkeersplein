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
	void haalUitWachtrij(Scenario*);
	Scenario* geefEersteInWachtrij();

private:
	List<Scenario*> *wachtrij;
};

#endif
