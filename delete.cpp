#include "labgui.h"

void deleteAcc(Fl_Widget*, void*)
{
	char theUser[255];

	if(win)
	{
		delete win;
		win = NULL;
	}

	cout << "***********************" << endl;
	cout << "*** Delete Account ***" << endl;
	cout << "***********************" << endl;
	cout << "Enter a subscriber you want to delete : "; 
	cin.getline(theUser, sizeof(theUser) - 1);
	cout << "***********************" << endl;
	cout << endl;

	if(stringLower(theUser) == stringLower(account->name))	
	fl_choice("You can't delete your own account.", "Ok", 0, 0);	
	else
	if(subscribers.remove(theUser))
	fl_choice("Account deleted successfully!", "Ok", 0, 0);	
	else
	fl_choice("Account not found. Delete failed.", "Ok", 0, 0);	

	createHome();
}
