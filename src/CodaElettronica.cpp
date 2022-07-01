using namespace std;
#include <iostream>
#include <memory>
#include <time.h>
#include <unistd.h>
#include <queue>
#include "Utente.h"
#include "Persona.h"
#include "Cliente.h"
#include "Gestore.h"
#include "ElettronicQueue.h"


unsigned long Utente::lastId=1000;//codice univoco di partenza Utenti
unsigned long ElettronicQueue::lastIdQ=100;//codice univoco di partenza EQ

int main() {
	printf("**********************************************************\n");
	printf("               PROGETTO  CODA ELETTRONICA\n");
	printf("**********************************************************\n");
	time_t now= time(NULL);//init now
	//creo clienti, gestore e coda
	Cliente c1= Cliente ("Paolo", "Rossi",true);
	Cliente c2= Cliente ("Luca", "Russo");
	Cliente c3= Cliente ("Giovanni", "Ferrari",true);
	Cliente c4= Cliente ("Alessandro", "Esposito");
	Cliente c5= Cliente ("Francesco", "Bianchi");
	Cliente c6= Cliente ("Nicola", "Romano",true);
	Gestore g1= Gestore("Davide", "Bruno");
	//ElettronicQueue* eq= ElettronicQueue::getInstance();//Singleton
	unique_ptr<ElettronicQueue> eq(ElettronicQueue::getInstance());

	//simulo gli arrivi c2->c3->c1->c6,c4->c5
	c2.setTimeReq(difftime(time(NULL),now));
	sleep(1);
	c3.setTimeReq(difftime(time(NULL),now));
	sleep(1);
	c1.setTimeReq(difftime(time(NULL),now));
	sleep(2);
	c6.setTimeReq(difftime(time(NULL),now));
	c4.setTimeReq(difftime(time(NULL),now));//stesso arrivo di c6 ma non prioritario
	sleep(1);
	c5.setTimeReq(difftime(time(NULL),now));
    g1.inServ(*eq);
	//1°caso
	g1.acceptCli(*eq, c2);
	g1.acceptCli(*eq, c1);
	g1.effServ(*eq);
	g1.next(*eq);
	//c1 viene servito prima pur essendo arrivato dopo-->prioritario
	//2° caso
	g1.acceptCli(*eq, c6);
	g1.acceptCli(*eq, c3);
	g1.effServ(*eq);
	g1.next(*eq);
	//c3 viene servito prima pur essendo stato accettato dopo--> stessa priorita(alta)--> fa fede il tempo di richiesta
	//c2 in quanto utente standard aspetta ancora
	g1.effServ(*eq);
	g1.next(*eq);
	g1.effServ(*eq);
	g1.next(*eq);
	g1.acceptCli(*eq, c4);
	g1.acceptCli(*eq, c5);
	g1.effServ(*eq);
	g1.next(*eq);
	g1.effServ(*eq);
	g1.next(*eq);
}
