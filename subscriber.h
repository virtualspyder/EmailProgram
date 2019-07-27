#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "email.h"

#define PrivilegeNormal 1
#define PrivilegeAdmin 5

// Subscriber 
struct Subscriber
{
	public : 
	Subscriber() { balance = 0.60; numSent = 0; }
	Subscriber(string nameX, string pass, int privilegeX)
	{
		numSent = 0;
		balance = 0.60;
		name = nameX;
		password = pass;
		privilege = privilegeX;
	}

	int privilege;
	double balance;
	int numSent;
	string name;
	string password;
	Queue<Email> unreads; 
	vector<Email> archived; 
};

#endif
