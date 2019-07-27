#include "labgui.h"

Fl_Button *buttonRead;
Fl_Button *buttonSend;
Fl_Button *buttonPass;
Fl_Button *buttonLogout;
Fl_Button *buttonChangeAll;
Fl_Button *buttonDel;
Fl_Button *buttonBal;
Fl_Button *buttonImport;
Fl_Button *buttonExport;
Fl_Button *buttonArchived;

Fl_Box *text1;
Fl_Box *text2;
Fl_Box *text3;
Fl_Box *text4;

void logOut(Fl_Widget*, void*)
{
	if(fl_choice("Are you sure you want to log out?", "No", "Yes", 0) == 1)
	{
		createLogin();
	}
}

void createHome()
{
	stringstream ss;
	if(win)
	{
		delete win;
		win = NULL;
	}

	win = new Fl_Window(600, 600);
	win->label("Home Box");

	static string welcome;
	static string accType;
	static string unreads;
	static string balance;

	ss << account->unreads.size();
	
	welcome = "Welcome, " + account->name;
	accType = "Account type : ";
	unreads = "Unread messages : " + ss.str();
	balance = "Your balance : $";

	ss.clear();
	ss.str("");

	ss.setf(std::ios::fixed);
	ss.precision(2);

	if(account->privilege == PrivilegeAdmin)
	accType += "Administrator User";	
	else
	accType += "Normal User";	

	ss << account->balance;

	balance += ss.str();

	ss.clear();
	ss.str("");

	text1 = new Fl_Box(0, 15, 600, 30, welcome.c_str());
	text2 = new Fl_Box(0, 45, 600, 30, accType.c_str());
	text3 = new Fl_Box(0, 75, 600, 30, unreads.c_str());
	text4 = new Fl_Box(0, 105, 600, 30, balance.c_str());

	text1->align(FL_ALIGN_CENTER);
	text2->align(FL_ALIGN_CENTER);
	text3->align(FL_ALIGN_CENTER);
	text4->align(FL_ALIGN_CENTER);

	buttonRead = new Fl_Button(220, 150, 150, 30, "Read eMails");
	buttonSend = new Fl_Button(220, 185, 150, 30, "Send eMails");
	buttonArchived = new Fl_Button(220, 220, 150, 30, "Archived eMails");
	buttonPass = new Fl_Button(220, 255, 150, 30, "Change Password");
	buttonLogout = new Fl_Button(220, 290, 150, 30, "Log Out");

	buttonPass->callback(changePass);
	buttonLogout->callback(logOut);
	buttonRead->callback(readQueue);
	buttonArchived->callback(readArchive);
	buttonSend->callback(composeMail);

	if(account->privilege == PrivilegeAdmin)
	{
		buttonChangeAll = new Fl_Button(220, 335, 150, 30, "Reset all password");
		buttonDel = new Fl_Button(220, 370, 150, 30, "Delete Account");
		buttonBal = new Fl_Button(220, 405, 150, 30, "Add Balance");
		buttonImport = new Fl_Button(220, 440, 150, 30, "Import system");
		buttonExport = new Fl_Button(220, 475, 150, 30, "Export system");

		buttonChangeAll->callback(resetPass);
		buttonDel->callback(deleteAcc);
		buttonBal->callback(addBal);
		buttonImport->callback(importSystem);
		buttonExport->callback(exportSystem);
	}

	win->show();
}
