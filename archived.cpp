#include "labgui.h"

Email archivedMsg;
Fl_Button *buttonReturn;

void returnHome(Fl_Widget*, void*)
{
	createHome();
}

void readArchive(Fl_Widget*, void*)
{
	if(account->archived.size() == 0)
	{
		fl_choice("You have no archived message.", "Ok", 0, 0);
		return;
	}

	createArchived();
}

void createArchived()
{
	if(win)
	{
		delete win;
		win = NULL;
	}
	int index;
	int total = account->archived.size();

	cout << "******************************" << endl;
	cout << "*** View archived messages ***" << endl;
	cout << "******************************" << endl;
	cout << "Total messages : " << total << endl;

	while(1)
	{
		cout << "Enter the message number you want to read : ";
		if(cin >> index)
		{
			if(index >= 1 && index <= total)
			{
				index -= 1;
				break;
			}
			else
			{
				cout << "Please enter a correct number!\n\n";
			}
		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Please enter a valid number!\n\n";
		} 
	}

	cout << "******************************" << endl;
	cout << endl;

	archivedMsg = account->archived[index];
	createArchived2();
}

void createArchived2()
{
	stringstream ss;
	if(win)
	{
		delete win;
		win = NULL;
	}

	ss << "From : " << archivedMsg.from << "\n";
	ss << "To : " << archivedMsg.to << "\n";
	ss << "Subject : " << archivedMsg.subject << "\n\n";
	ss << archivedMsg.text;

	win = new Fl_Window(600, 600);
	win->label("Read Archived Message");

	buffer = new Fl_Text_Buffer();
	textBox = new Fl_Text_Editor(10, 10, 580, 500);
	textBox->buffer(buffer);
	buffer->text(ss.str().c_str());

	buttonReturn = new Fl_Button(250, 520, 100, 30, "Return");
	buttonReturn->callback(returnHome);

	win->show();
}
