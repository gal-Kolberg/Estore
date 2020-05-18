#ifndef __FEEDBACK_H
#define __FEEDBACK_H

#include "Date.h"
#include "MainHeader.h"

class Date;

class Feedback
{
public:
	Feedback (string feedback = string(),Date* date = nullptr);
	Feedback(const Feedback& other);
	const Feedback& operator=(const Feedback & other);
	~Feedback();

	string getFeedback() const;
	Date* getDate() const;

	friend ostream& operator<<(ostream&  os, const Feedback &f);

	void  print();
	void  setFeedback(string feedback);
	void setDate(Date *date);
private:
	Date *m_date;
	string  m_feedback;
};
#endif