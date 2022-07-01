/*
 * Persona.h
 *
 *  Created on: 28 giu 2022
 *      Author: nicol
 */

#ifndef PERSONA_H_
#define PERSONA_H_
#include <iostream>
using namespace std;

class Persona {
public:
	string nome;
	string cognome;
	Persona(string n,string c);
	Persona();
	virtual ~Persona();
};

#endif /* PERSONA_H_ */
