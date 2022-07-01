/*
 * Gestore.h
 *
 *  Created on: 29 giu 2022
 *      Author: nicol
 */

#ifndef GESTORE_H_
#define GESTORE_H_
#include <iostream>
using namespace std;
#include "Persona.h"
#include "Utente.h"
#include "ElettronicQueue.h"
class Gestore:public Persona, public Utente {
public:
	int status;//0-->free 1-->in servizio 2-->occupato
	Gestore(string n, string c);
	Gestore(Persona p,Utente u);
	~Gestore();

	int getStatus() const {
		return status;
	}

	void setStatus(int status) {
		this->status = status;
	}
	void inServ(ElettronicQueue &q);
	void effServ(ElettronicQueue &q);
	void next(ElettronicQueue &q);
	void acceptCli(ElettronicQueue &q,Cliente &c);
};

#endif /* GESTORE_H_ */
