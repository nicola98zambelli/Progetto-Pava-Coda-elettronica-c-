/*
 * Cliente.cpp
 *
 *  Created on: 28 giu 2022
 *      Author: nicol
 */
#include "Cliente.h"

Cliente::Cliente(Persona p, Utente u):
Utente(u.id), Persona(p.nome,p.cognome),priority(0),timeReq(0){}

Cliente::Cliente(string n, string c,bool p):
		Utente(), Persona(n,c),priority(p),timeReq(0){}//super

Cliente::Cliente(string n, string c):
		Cliente(n,c,false){}//this

Cliente::~Cliente() {
}


