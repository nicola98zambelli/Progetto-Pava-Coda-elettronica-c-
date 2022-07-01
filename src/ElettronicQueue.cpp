/*
 * ElettronicQueue.cpp
 *
 *  Created on: 29 giu 2022
 *      Author: nicol
 */

#include "ElettronicQueue.h"
ElettronicQueue* ElettronicQueue::instance = 0;
ElettronicQueue::ElettronicQueue() {
	idQ=++lastIdQ;
}
ElettronicQueue* ElettronicQueue::getInstance(){
	if(instance == 0){
		instance = new ElettronicQueue();
	}
	return instance;
}
void ElettronicQueue::printNext(){
	{
		if(!this->priority.empty()){
			cout<<"Prossimo utente in attesa: "<<this->priority.top().id<<endl;
		}else if(!this->standard.empty()){
			cout<<"Prossimo utente in attesa: "<<this->standard.top().id<<endl;
		}else{
			cout<<"Nessun cliente in Attesa"<<endl;
		}
		cout<<"----------------------------------------------------------\n";
	}
}
ElettronicQueue::~ElettronicQueue() {
	delete(instance);
}

