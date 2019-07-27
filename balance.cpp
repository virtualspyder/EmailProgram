#include "labgui.h"

void addBal(Fl_Widget*, void*)
{
	char theUser[255];
	stringstream ss;
	if(win)
	{
		delete win;
		win = NULL;
	}
	double add = 0.00;
	cout << "*****************************" << endl;
	cout << "*** Add Account's Balance ***" << endl;
	cout << "*****************************" << endl;
	Subscriber *acc;
	while(1)
	{
		cout << "Enter an account : ";
		cin.getline(theUser, sizeof(theUser) - 1);

		if(!findUser(theUser, acc))	
		cout << "The account does not exist.\n\n";
		else
		break;
	}

	cout << "Enter the balance to add : $";
	cin >> add;
	cin.ignore();

	if(add >= 0)
	{
		acc->balance += add;
		ss.setf(std::ios::fixed);
		ss.precision(2);
		ss << "Success! You have added $" << add << " to " << acc->name << "'s balance!";
		fl_choice(ss.str().c_str(), "Ok", 0, 0);
	}
	else
	{
		fl_choice("The amount must be at least $0.00 or greater.", "Ok", 0, 0);
	}

	cout << "*****************************" << endl;
	cout << endl;
	createHome(); 
}
