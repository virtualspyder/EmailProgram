#include <FL/Fl.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Secret_Input.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Text_Editor.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Multiline_Input.H>

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <fstream>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::map;
using std::vector;
using std::stringstream;
using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;

#include "queue.hpp"
#include "tree.h"

extern void createLogin();
extern void createHome();
extern void createRead();
extern void createArchived();
extern void createArchived2();

extern void importSystem(istream &is);
extern void exportSystem(ostream &os);
extern void exportEmail(ostream &os, const Email& msg);
extern void importEmail(istream &is, Email& msg);
extern void exportSubscriber(ostream &os, const Subscriber& acc);
extern void importSubscriber(istream &is, Subscriber& acc);

extern void buttonLogin(Fl_Widget*, void*);
extern void changePass(Fl_Widget*, void*);
extern void resetPass(Fl_Widget*, void*);
extern void logOut(Fl_Widget*, void*);
extern void readQueue(Fl_Widget*, void*);
extern void readArchive(Fl_Widget*, void*);
extern void deleteMsg(Fl_Widget*, void*);
extern void archiveMsg(Fl_Widget*, void*);
extern void returnHome(Fl_Widget*, void*);
extern void composeMail(Fl_Widget*, void*);
extern void sendMessage(Fl_Widget*, void*);
extern void resetPass(Fl_Widget*, void*);
extern void deleteAcc(Fl_Widget*, void*);
extern void addBal(Fl_Widget*, void*);
extern void importSystem(Fl_Widget*, void*);
extern void exportSystem(Fl_Widget*, void*);

extern void login(string name, string pass);
extern bool newUser(string name, string pass, int privilege);
extern bool findUser(string name, Subscriber *&acc);

extern Fl_Window *win;
extern Fl_Input *editBox;
extern Fl_Input *editBox2;
extern Fl_Multiline_Input *editBoxMul;

extern Fl_Secret_Input *passwordEditBox;
extern Fl_Button *button;
extern Fl_Button *button2;
extern Fl_Button *button3;
extern BinarySearchTree subscribers;
extern Subscriber *account;
extern Email unreadMsg;
extern Email archivedMsg;
extern double currentRate;

extern Fl_Button *buttonRead;
extern Fl_Button *buttonSend;
extern Fl_Button *buttonPass;
extern Fl_Button *buttonArchived;
extern Fl_Button *buttonLogout;
extern Fl_Button *buttonChangeAll;
extern Fl_Button *buttonDel;
extern Fl_Button *buttonBal;
extern Fl_Button *buttonImport;
extern Fl_Button *buttonExport;
extern Fl_Button *buttonArchive;
extern Fl_Button *buttonReturn;

extern Fl_Box *text1;
extern Fl_Box *text2;
extern Fl_Box *text3;
extern Fl_Box *text4;

extern Fl_Text_Buffer* buffer; 
extern Fl_Text_Editor* textBox; 


