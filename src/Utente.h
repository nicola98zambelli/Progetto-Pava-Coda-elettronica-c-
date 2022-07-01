/*
 * Utente.h
 *
 *  Created on: 28 giu 2022
 *      Author: nicol
 */

#ifndef UTENTE_H_
#define UTENTE_H_
#include <iostream>
using namespace std;
class Utente {
public:
	unsigned long id;
	Utente();
	Utente(long id);
	virtual ~Utente();

	unsigned long getId() const {
		return id;
	}

	void setId(unsigned long id) {
		this->id = id;
	}
    virtual void print(){
    	cout<<"Utente n°"<<this->id<<endl;
    }//classe utente
private:
	static unsigned long lastId;
};

#endif /* UTENTE_H_ */
