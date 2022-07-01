/*
 * Cliente.h
 *
 *  Created on: 28 giu 2022
 *      Author: nicol
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "Persona.h"
#include "Utente.h"



class Cliente: public Persona, public Utente {
public:
	bool priority;
	double timeReq;//tempo trascorso tra inizio e richiesta


	Cliente(string n, string c, bool p);
	Cliente(string n, string c);
	Cliente(Persona p,Utente u);
	~Cliente();

	bool isPriority() const {
		return priority;
	}
	void print(){
		cout<<"Utente n°"<<this->id<<", "<<this->nome<<" "<<this->cognome<<endl;
	}//classe Cliente
	void setPriority(bool priority) {
		this->priority = priority;
	}
	double getTimeReq() const {
		return timeReq;
	}

	void setTimeReq(double timeReq) {
		this->timeReq = timeReq;
	}
};
struct CompareClient {
	bool operator()(Cliente const& c1, Cliente const& c2){
		return c1.timeReq > c2.timeReq;
		//ritorna vero se é ordinato in base al tempo di richiesta
	}
};

#endif /* CLIENTE_H_ */
