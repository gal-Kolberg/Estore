#include "Feedback.h"

Feedback::Feedback(string feedback, Date* date)
{
	setDate(date);
	setFeedback(feedback);
}

Feedback::Feedback(const Feedback & other)
{
	this->m_date = other.m_date;
	this->m_feedback = other.m_feedback;
}

const Feedback & Feedback::operator=(const Feedback & other)
{
	m_date = new Date(*other.m_date);
	m_feedback = other.m_feedback;
	return *this;
}

Feedback::~Feedback()
{
	delete m_date;
}

string Feedback::getFeedback() const
{
	return m_feedback;
}

Date* Feedback::getDate() const
{
	return m_date;
}

void Feedback::print()
{
	cout << m_feedback << endl;
}

void Feedback::setFeedback(string feedback)
{
	m_feedback = feedback;
}

void Feedback::setDate(Date * date)
{
	m_date = date;
}

ostream & operator<<(ostream & os, const Feedback & f)
{
	os << "Feedback was given at: " << *(f.m_date) << "The feedback is: " << f.m_feedback << "\n\n";
	return os;
}
