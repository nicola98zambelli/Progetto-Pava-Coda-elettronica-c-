/*
 * ElettronicQueue.h
 *
 *  Created on: 29 giu 2022
 *      Author: nicol
 */

#ifndef ELETTRONICQUEUE_H_
#define ELETTRONICQUEUE_H_
#include <iostream>
using namespace std;
#include <queue>
#include "Cliente.h"

class ElettronicQueue {
public:
	priority_queue<Cliente, vector<Cliente>, CompareClient> priority;
	priority_queue<Cliente, vector<Cliente>, CompareClient> standard;
	unsigned long idQ;
	static ElettronicQueue* getInstance();
	void printNext();
	virtual ~ElettronicQueue();
private:
	static unsigned long lastIdQ;
	static ElettronicQueue* instance;
	ElettronicQueue();
};

#endif /* ELETTRONICQUEUE_H_ */
