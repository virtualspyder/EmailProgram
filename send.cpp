#include "labgui.h"

Fl_Input *editBox2;
Fl_Multiline_Input *editBoxMul;

void sendMessage(Fl_Widget*, void*)
{
	string from = account->name;
	string to = editBox->value();
	string subject = editBox2->value();
	string text = editBoxMul->value();

	Subscriber *acc;
	if(!findUser(to, acc))
	{
		if(fl_choice("Subscriber not found. Are you sure you want to create this account?", "No", "Yes", 0) == 1)
		{
			newUser(to, "", PrivilegeNormal);
			fl_choice("Subscriber created!", "Ok", 0, 0);
			findUser(to, acc);		
		}
		else return;
	}

	acc->unreads.push(Email(to, from, subject, text));
	account->numSent++;
	account->balance -= currentRate;
	fl_choice("Message sent successfully!", "Ok", 0, 0);
	
	createHome();
}

void composeMail(Fl_Widget*, void*)
{
	stringstream ss;
	if(account->balance < currentRate)
	{
		fl_choice("You don't have enough balance to send messages.", "Ok", 0, 0);
		return;
	}

	if(win)
	{
		delete win;
		win = NULL;
	}

	win = new Fl_Window(600, 600);
	win->label("Send message");

	static string messageRate;
	messageRate = "Current message rate : $";
	ss << currentRate << " per message";
	messageRate += ss.str();

	text1 = new Fl_Box(0, 15, 600, 30, messageRate.c_str());

	editBox = new Fl_Input(100, 50, 380, 30, "To : ");
	editBox->value("Subscriber");
	editBox2 = new Fl_Input(100, 85, 380, 30, "Subject : ");
	editBoxMul = new Fl_Multiline_Input(100, 120, 380, 385);
	editBoxMul->value("Enter your message here. . .");

	buttonSend = new Fl_Button(50, 520, 100, 30, "Send");
	buttonReturn = new Fl_Button(440, 520, 100, 30, "Return");

	buttonSend->callback(sendMessage);
	buttonReturn->callback(returnHome);

	win->show();
}
