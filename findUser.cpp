#include "labgui.h"

bool findUser(string name, Subscriber *&acc)
{
	return subscribers.find(name, acc);
}