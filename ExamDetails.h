#ifndef EXAMDETAILS_H_ //ExamDetails.h
#define EXAMDETAILS_H_
#include <string>
#include <iostream>
using std::ostream;
using std::string;
using std::endl;

namespace mtm
{
	const int MTM_COURSE_ID = 234124;
	const int MTM_EXAM_MONTH = 7;
	const int MTM_EXAM_DAY = 28;
	const double MTM_EXAM_HOUR = 13.0f;
	const int MTM_EXAM_DURATION = 3;
	const string MTM_EXAM_LINK = "https://tinyurl.com/59hzps6m";

	const int DAYS_IN_MONTH = 30;

	class ExamDetails
	{
	public:
		ExamDetails(int course, int month, int day, float hour, int duration, string link); // constructor
		~ExamDetails() = default; //destructor

		ExamDetails(const ExamDetails& exam); //copy consructor
		ExamDetails& operator=(const ExamDetails&); //ex1 = ex2

		string getLink() const;
		void setLink(string new_link);

		friend int operator-(const ExamDetails& left, const ExamDetails& right);
		friend ostream& operator<<(ostream& left, const ExamDetails& right);

		static ExamDetails makeMatamExam();


	private:
		int course, month, day, duration;
		float hour;
		string link;

		static string makeHourToString(float hour);

	};

	bool operator<(const ExamDetails& left, const ExamDetails& right);

}


#endif //ExamDetails.h