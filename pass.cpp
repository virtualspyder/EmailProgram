#include "labgui.h"

void changePass(Fl_Widget*, void*)
{
	char newPass[255];
	if(win)
	{
		delete win;
		win = NULL;
	}

	cout << "***********************" << endl;
	cout << "*** Change Password ***" << endl;
	cout << "***********************" << endl;
	cout << "Enter new subcriber's password : "; 
	cin.getline(newPass, sizeof(newPass) - 1);
	account->password = newPass;
	cout << "Password changed successfully!" << endl;
	fl_choice("Password changed successfully!", "Ok", 0, 0);
	cout << "***********************" << endl;
	cout << endl;

	createHome();
}

void resetPass(Fl_Widget*, void*)
{
	char newPass[255];
	if(win)
	{
		delete win;
		win = NULL;
	}

	cout << "***************************" << endl;
	cout << "*** Change All Password ***" << endl;
	cout << "***************************" << endl;
	cout << "Enter new password for all subcribers : "; 
	cin.getline(newPass, sizeof(newPass) - 1);
	for(BinarySearchTree::iterator it = subscribers.begin(); it != subscribers.end(); it++)
	{
		it->second.password = newPass;
	}
	cout << "Password changed successfully!" << endl;
	fl_choice("Password changed successfully!", "Ok", 0, 0);
	cout << "***************************" << endl;

	createHome();
}
