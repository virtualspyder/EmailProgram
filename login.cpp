#include "labgui.h"

Fl_Input *editBox;
Fl_Secret_Input *passwordEditBox;
Fl_Button *button;

void buttonLogin(Fl_Widget*, void*)
{
	string name = editBox->value();
	string pass = passwordEditBox->value();

	login(name, pass);
}

void createLogin()
{
	if(win)
	{
		delete win;
		win = NULL;
	}

	win = new Fl_Window(600, 480);
	win->label("Login Box");

	editBox = new Fl_Input(100, 80, 360, 30, "Username : ");
	editBox->value("Subscriber");
	passwordEditBox = new Fl_Secret_Input(100, 115, 360, 30, "Password: ");
	passwordEditBox->value("Password");
	button = new Fl_Button(100, 150, 100, 30, "Log in");
	button->callback(buttonLogin);

	win->show();
}

void login(string name, string pass)
{
	Subscriber *acc;
	if(findUser(name, acc))
	{
		if(acc->password == pass)
		{
			fl_choice("Thank you, you have logged in.", "Ok", 0, 0);
			account = acc;
			createHome();
		}
		else		
		fl_choice("Wrong password.", "Ok", 0, 0);			
	}
	else
	{
		if(pass.size())
		fl_choice("Subscriber not found. Empty the password to create new account.", "Okay", 0, 0);
		else
		{
			if(fl_choice("Are you sure you want to create an account?", "No", "Yes", 0) == 1)
			{
				if(newUser(name, pass, PrivilegeNormal))
				{
					fl_choice("Subscriber created!", "Ok", 0, 0);
					findUser(name, acc);
					account = acc;
					createHome();
				}
			}
		}
	}
}
