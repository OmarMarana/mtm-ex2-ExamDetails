 #ifndef EXAMDETAILS_H_ //ExamDetails.h
 #define EXAMDETAILS_H_
#include <string>
#include <iostream>


namespace mtm
{
	const std::string HOUR_HALF = "30";
	const std::string FULL_HOUR = "00";

	const int MTM_COURSE_ID = 234124;
	const int MTM_EXAM_MONTH = 7;
	const int MTM_EXAM_DAY = 28;
	const double MTM_EXAM_HOUR = 13.0f;
	const int MTM_EXAM_DURATION = 3;
	const std::string MTM_EXAM_LINK = "https://tinyurl.com/59hzps6m";

	const int DAYS_IN_MONTH = 30;
	const int FIRST_MONTH = 1;
	const int LAST_MONTH = 12;
	const int FIRST_DAY = 1;
	const float FIRST_HOUR = 0.0f;
	const float LAST_HOUR = 24.0f;
	const float EPSILON = 10E-6;
	const float HALF = 0.5f;
	
	class ExamDetails
	{
	public:
		ExamDetails(int course, int month, int day, float hour, int duration, std::string link);
		~ExamDetails() = default;

		ExamDetails(const ExamDetails& exam);
		ExamDetails& operator=(const ExamDetails&);

		std::string getLink() const;
		void setLink(std::string new_link);

		friend int operator-(const ExamDetails& left, const ExamDetails& right);
		friend std::ostream& operator<<(std::ostream& stream, const ExamDetails& exam);

		static ExamDetails makeMatamExam();

		class InvalidDateException{};
		class InvalidTimeException{};
		class InvalidArgsException{};
		
	private:
		int course, month, day, duration;
		float hour;
		std::string link;

		static std::string makeHourToString(float hour);
		static bool inRange(double value ,double center, double range);
		static bool isHourValid(float hour);

	};

	bool operator<(const ExamDetails& left, const ExamDetails& right);
}
#endif //ExamDetails.h