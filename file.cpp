#include "labgui.h"

void importSystem(istream &is)
{
	size_t i;
	size_t subscribersSize = 0;

	string adminName = account->name;
	is >> subscribersSize;
	
	cout << "************************" << endl;
	cout << "*** Import Data ***" << endl;
	cout << "************************" << endl;

	subscribers.clear();
	for(i = 0; i < subscribersSize; i++)
	{
		cout << "+ Subscriber " << i + 1 << " : ";
		Subscriber acc;
		importSubscriber(is, acc);
		subscribers.add(acc);
		cout << "Done.\n";
	}

	cout << "************************" << endl;
	
	findUser(adminName, account);
}

void exportSystem(ostream &os)
{
	os << subscribers.size() << ' ';
	for(BinarySearchTree::iterator it = subscribers.begin(); it != subscribers.end(); it++)
	{
		exportSubscriber(os, it->second);
	}
}

void exportEmail(ostream &os, const Email& msg)
{
	size_t i;
	os << msg.from.size() << ' ';
	os << msg.to.size() << ' ';
	os << msg.subject.size() << ' ';
	os << msg.text.size() << ' ' << '^';

	for(i = 0; i < msg.from.size(); i++) os << msg.from[i];
	for(i = 0; i < msg.to.size(); i++) os << msg.to[i];
	for(i = 0; i < msg.subject.size(); i++) os << msg.subject[i];
	for(i = 0; i < msg.text.size(); i++) os << msg.text[i]; 
	os << ' ' << '\n';	
}

void importEmail(istream &is, Email& msg)
{
	size_t i;
	char hat, c;
	size_t fromSize;
	size_t toSize;
	size_t subjectSize;
	size_t textSize;

	is >> fromSize;
	is >> toSize;
	is >> subjectSize;
	is >> textSize;
	is >> hat;

	msg.from = "";
	msg.to = "";
	msg.subject = "";
	msg.text = "";

	for(i = 0; i < fromSize; i++) {
		c = is.get(); msg.from += c;
	}

	for(i = 0; i < toSize; i++) {
		c = is.get(); msg.to += c;
	}

	for(i = 0; i < subjectSize; i++) {
		c = is.get(); msg.subject += c;
	}

	for(i = 0; i < textSize; i++) {
		c = is.get(); msg.text += c;
	}
}

void exportSubscriber(ostream &os, const Subscriber& acc)
{
	size_t i;
	os << acc.privilege << ' ';
	os << acc.balance << ' ';
	os << acc.numSent << ' ' << '^';
	os << acc.name << '\n';
	os << acc.password << '\n';

	Queue<Email> unreads = acc.unreads;
	vector<Email> archived = acc.archived;

	os << acc.unreads.size() << ' ' << '\n';

	Email msg;
	while(!unreads.isEmpty())
	{
		msg = unreads.front();
		exportEmail(os, msg);
		unreads.pop();
	}

	os << archived.size() << ' ' << '\n';

	for(i = 0; i < archived.size(); i++)
	{
		exportEmail(os, archived[i]);
	}
}


void importSubscriber(istream &is, Subscriber& acc)
{
	size_t i;
	size_t unreadsSize = 0, archivedSize = 0;
	char hat;
	is >> acc.privilege;
	is >> acc.balance;
	is >> acc.numSent;
	is >> hat;
	std::getline(is, acc.name);
	std::getline(is, acc.password);

	is >> unreadsSize;
	acc.unreads.clear();

	cout << " Phase 1 - ";

	Email msg;
	for(i = 0; i < unreadsSize; i++)
	{
		importEmail(is, msg);
		acc.unreads.push(msg);
	}

	cout << " Phase 2 - ";
	 
	is >> archivedSize;
	acc.archived.clear();
	for(i = 0; i < archivedSize; i++)
	{
		importEmail(is, msg);
		acc.archived.push_back(msg);
	}
}
