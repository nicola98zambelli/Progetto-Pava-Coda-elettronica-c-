
#include "Persona.h"

Persona::Persona(string n,string c) {
	nome=n;
	cognome=c;
	//cout<<"CREO PERSONA:"<<nome<<" "<<cognome<<endl;
}
Persona::Persona() {
	nome="NOME";
	cognome="COGNOME";
	//cout<<"CREO PERSONA VUOTA"<<endl;
}
Persona::~Persona() {
	//cout<<"DISTRUGGO PERSONA:"<<nome<<" "<<cognome<<endl;
}

