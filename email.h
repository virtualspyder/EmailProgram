#ifndef EMAIL_H
#define EMAIL_H

struct Email
{
	Email() {}
	Email(string toX, string fromX, string subjectX, string textX) 
	{
		to = toX;
		from = fromX;
		subject = subjectX;
		text = textX;
	}

	string to, from, subject, text;
};

#endif