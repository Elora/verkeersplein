#include "wachtrijbeheerder.h"

WachtrijBeheerder::WachtrijBeheerder(List<Scenario*>* w) : wachtrij(w){

}

void WachtrijBeheerder::voegToe(Scenario *s){
	if (!doorzoekWachtrij(s))
		wachtrij->push_back(s);
}

bool WachtrijBeheerder::doorzoekWachtrij(Scenario *s){
	return wachtrij->komtAlVoor(s);
}

void WachtrijBeheerder::haalEersteUitWachtrij(){
	wachtrij->pop_front();
}

void WachtrijBeheerder::haalUitWachtrij(Scenario *s){
	wachtrij->haalUitLijst(s);
}

Scenario* WachtrijBeheerder::geefEersteInWachtrij(){
	return wachtrij->krijgKop();
}
