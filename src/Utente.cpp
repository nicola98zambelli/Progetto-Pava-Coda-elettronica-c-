/*
 * Utente.cpp
 *
 *  Created on: 28 giu 2022
 *      Author: nicol
 */

#include "Utente.h"
Utente::Utente() {
id=++lastId;
//cout<<"CREO UTENTE ID:"<<id<<endl;
}
Utente::Utente(long id) {
this->id=id;
}
Utente::~Utente() {
	//cout<<"DISTRUGGO UTENTE ID:"<<id<<endl;
}

