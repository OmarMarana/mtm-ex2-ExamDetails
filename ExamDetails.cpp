#include "ExamDetails.h"
using namespace mtm;



//add error exception handling later...
ExamDetails::ExamDetails(int course, int month, int day, float hour, int duration, string link) :
	course(course), month(month), day(day), hour(hour), duration(duration), link(link)
{ }

/* destructor, right now is defined to default...*/
// ExamDetails::~ExamDetails()
// {};

/* copy constructor*/
ExamDetails::ExamDetails(const ExamDetails& exam) :
	course(exam.course), month(exam.month), day(exam.day), hour(exam.hour), duration(exam.duration), link(exam.link)
{ }


//ref to a string or copy constructor for string?
string ExamDetails::getLink() const
{
	return link;
}

void ExamDetails::setLink(string new_link)
{
	link = new_link;
}

bool operator<(const ExamDetails& left, const ExamDetails& right)
{
	return (left - right < 0);
}

//return the days difference between LEFT and right.
int mtm::operator-(const ExamDetails& left, const ExamDetails& right)
{
	int month_diff = left.month - right.month;
	int days_diff = left.day - right.day;
	//Ex:    L R
	int result = month_diff * DAYS_IN_MONTH; //months 3 1   --> res = 60
	result += days_diff;                     //days   5 1   --> res += (5-1)  ---> res = 64

	return result;
}

ExamDetails& ExamDetails::operator=(const ExamDetails& exam)
{
	if (this == &exam)
	{
		return *this;
	}
	course = exam.course;
	month = exam.month;
	day = exam.day;
	duration = exam.duration;
	hour = exam.hour;
	link = exam.link;

	return *this;
}


ostream& mtm::operator<<(ostream& stream, const ExamDetails& exam)
{
	// Course Number: 104032
	// Time: 11.7 at 9:30
	// Duration: 3:00
	// Zoom Link:

    

	return stream << "Course Number: " << exam.course << endl <<
		"Time: " << exam.day << "." << exam.month << " at " << ExamDetails::makeHourToString(exam.hour)
                 << endl <<
		"Duration: " << ExamDetails::makeHourToString(exam.duration) << endl <<
		"Zoom Link: " << exam.link << endl;
}

//check to_string
string ExamDetails::makeHourToString(float hour)
{
	// example 9:30
	string str = "";
	str += std::to_string((int)hour); //c++ 11
	str += ":";

	//str = "9:"
	if (hour - (int)hour > 0)
	{
		return (str + "30");
	}

	return str + "00";
}


ExamDetails ExamDetails::ExamDetails::makeMatamExam()
{
	return ExamDetails(MTM_COURSE_ID, MTM_EXAM_MONTH, MTM_EXAM_DAY,
		MTM_EXAM_HOUR, MTM_EXAM_DURATION, MTM_EXAM_LINK);
}
