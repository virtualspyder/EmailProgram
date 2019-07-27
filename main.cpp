#include "labgui.h"

Subscriber *account;
double currentRate = 0.19;

string stringLower(string s)
{
	for(size_t i = 0; i < s.size(); i++) s[i] = tolower(s[i]);
	return s;
}

Fl_Window *win = NULL;
BinarySearchTree subscribers;

int main()
{
	Subscriber *acc;
	newUser("SYSOP", "admin", PrivilegeAdmin);
	findUser("SYSOP", acc);

	acc->unreads.push(Email("SYSOP", "SYSOP", "First welcome", "Welcome to Email Program!"));
	createLogin();
	return Fl::run();
}
