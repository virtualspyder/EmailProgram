#include "labgui.h"

Fl_Button *buttonArchive;
Fl_Text_Buffer* buffer; 
Fl_Text_Editor* textBox; 
Email unreadMsg;

void readQueue(Fl_Widget*, void*)
{
	if(account->unreads.size() == 0)
	{
		fl_choice("You have no unread message.", "Ok", 0, 0);
		return;
	}
	createRead();
}

void deleteMsg(Fl_Widget*, void*)
{
	fl_choice("This message has been deleted.", "Ok", 0, 0);
	createHome();
}

void archiveMsg(Fl_Widget*, void*)
{
	account->archived.push_back(unreadMsg);
	fl_choice("This message has been archived.", "Ok", 0, 0); 
	createHome();
}

void createRead()
{
	stringstream ss;
	if(win)
	{
		delete win;
		win = NULL;
	}

	unreadMsg = account->unreads.front();
	account->unreads.pop();

	ss << "From : " << unreadMsg.from << "\n";
	ss << "To : " << unreadMsg.to << "\n";
	ss << "Subject : " << unreadMsg.subject << "\n\n";
	ss << unreadMsg.text;

	win = new Fl_Window(600, 600);
	win->label("Read Message");

	buffer = new Fl_Text_Buffer();
	textBox = new Fl_Text_Editor(10, 10, 580, 500);
	textBox->buffer(buffer);
	buffer->text(ss.str().c_str());

	buttonArchive = new Fl_Button(50, 520, 100, 30, "Archive");
	buttonDel = new Fl_Button(440, 520, 100, 30, "Delete");

	buttonArchive->callback(archiveMsg);
	buttonDel->callback(deleteMsg);

	win->show();
}
