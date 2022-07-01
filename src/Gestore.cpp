/*
 * Gestore.cpp
 *
 *  Created on: 29 giu 2022
 *      Author: nicol
 */
#include "Gestore.h"

Gestore::Gestore(Persona p,Utente u):
Utente(u.id), Persona(p.nome,p.cognome),status(0){}

Gestore::Gestore(string n, string c):
Utente(), Persona(n,c),status(0){}
void Gestore::inServ(ElettronicQueue &q){
	this->status=1;
	cout<<"Gestore della coda n°"<<q.idQ<<", Utente n°"<<
			this->id<<" : "<<this->nome<<" "<<this->cognome<<endl;
	printf("__________________________________________________________\n");
}

void Gestore::effServ(ElettronicQueue &q){
	if(!q.priority.empty()){    //cerco prima nella coda prioritaria se questa non é vuota
		this->status=2;
		cout<<"Servo il cliente n°"<<q.priority.top().id<<" "<<q.priority.top().nome
				<<" "<<q.priority.top().cognome<<" AT:"<<q.priority.top().timeReq
				<<" (P)"<<endl;
	}else if(!q.standard.empty()){
		this->status=2;
		cout<<"Servo il cliente n°"<<q.standard.top().id<<" "<<q.standard.top().nome
				<<" "<<q.standard.top().cognome<<" AT:"<<q.standard.top().timeReq
				<<" (S)"<<endl;
	}else{
		cout<<" Nessun cliente in Attesa"<<endl;//non cambio stato
	}
}

void Gestore::next(ElettronicQueue &q){
	this->status=1;//in qualunque caso
	if(!q.priority.empty()){
		q.priority.pop();
		q.printNext();
	}else if(!q.standard.empty()){
		q.standard.pop();
		q.printNext();
	}else{
		cout<<" Nessun cliente in Attesa"<<endl;
	}
}

void Gestore::acceptCli(ElettronicQueue &q,Cliente &c){
	(c.priority==true)? q.priority.push(c) : q.standard.push(c);
	cout<<"Il cliente "<<c.id<<" "<<c.nome<<" "<<c.cognome<<" è in attesa(";
	(c.priority==true)? cout<<"P)"<<endl : cout<<"S)"<<endl;
	cout<<"----------------------------------------------------------\n";
}
Gestore::~Gestore() {}



