#include "ExamDetails.h"
using namespace mtm;
using std::ostream;
using std::string;
using std::endl;

//constructor of ExamDetails
ExamDetails::ExamDetails(int course, int month, int day, float hour, int duration, string link) :
	course(course), month(month), day(day), hour(hour), duration(duration), link(link)
{
	if(course <= 0)
	{
		throw InvalidArgsException();
	}
	
	if(month < FIRST_MONTH || month > LAST_MONTH ||
	   day < FIRST_DAY || day > DAYS_IN_MONTH)	
	{
		throw InvalidDateException();
	}		
	
	if(hour < FIRST_HOUR || hour > LAST_HOUR || !isHourValid(hour))
	{
		throw InvalidTimeException();
	}

	if(duration <= 0)
	{
		throw InvalidArgsException();
	}
}

/* copy constructor */
ExamDetails::ExamDetails(const ExamDetails& exam) :
	course(exam.course), month(exam.month), day(exam.day), hour(exam.hour), duration(exam.duration), link(exam.link)
{ }

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


string ExamDetails::getLink() const
{
	return link;
}

void ExamDetails::setLink(string new_link)
{
	link = new_link;
}

/* return true if exam left is BEFORE exam right.*/
bool operator<(const ExamDetails& left, const ExamDetails& right)
{
	return (left - right < 0);
}

/* static constructor with default values.*/
ExamDetails ExamDetails::ExamDetails::makeMatamExam()
{
	return ExamDetails(MTM_COURSE_ID, MTM_EXAM_MONTH, MTM_EXAM_DAY,
		MTM_EXAM_HOUR, MTM_EXAM_DURATION, MTM_EXAM_LINK);
}

/* return the difference in days from exam left to exam right*/
/* this function is friend function of class ExamDetails.*/
int mtm::operator-(const ExamDetails& left, const ExamDetails& right)
{
	int month_diff = left.month - right.month;
	int days_diff = left.day - right.day;
	
	int result = month_diff * DAYS_IN_MONTH; 
	result += days_diff;                     

	return result;
}

/*Print ExamDetails*/
std::ostream& mtm::operator<<(std::ostream& stream, const ExamDetails& exam)
{
	return stream << "Course Number: " << exam.course << std::endl <<
		"Time: " << exam.day << "." << exam.month << " at " << ExamDetails::makeHourToString(exam.hour)
				<< std::endl <<
		"Duration: " << ExamDetails::makeHourToString(exam.duration) << std::endl <<
		"Zoom Link: " << exam.link << std::endl;
}

/* Example: convert 9.5 into 9:30 */
string ExamDetails::makeHourToString(float hour)
{
	string str = "";
	str += std::to_string((int)hour);
	str += ":";

	if (hour - (int)hour > 0)
	{
		return (str + "30");
	}

	return str + "00";
}

/* return true if hour is full or half hour/*/
bool ExamDetails::isHourValid(float hour)
{
	float rslt = hour - (int)hour;

	if(!inRange(rslt, FIRST_HOUR, EPSILON) && !inRange(rslt, HALF, EPSILON))
	{
		return false;
	}

	return true;
}

bool ExamDetails::inRange(double value ,double center, double range)
{
	return (value > center - range && value < center + range);
}