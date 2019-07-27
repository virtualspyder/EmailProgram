#include "labgui.h"

bool newUser(string name, string pass, int privilege)
{
	Subscriber sub(name, pass, privilege);
	return subscribers.add(sub);
}