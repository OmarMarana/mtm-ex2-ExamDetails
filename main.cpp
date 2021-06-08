#include <iostream>
#include <string>
#include "ExamDetails.h"

using std::ostream;
using std::string;
using std::endl;
using std::cout;
using namespace mtm;


int main(int, char**)
{
    int course = 50;
    int month = 10;
    int day = 5;
    float hour = 24.0;
    int duration = 2;
    string link = "fff";

    try
    {
        ExamDetails ex1(course, month, day, hour, duration, link);
        ExamDetails ex2(course, month, day, hour, duration, link);
        
        cout << ex1 << endl;
        cout << ex2 << endl;

        cout << "Diff in days: " << ex1 - ex2 << endl;
    }
    catch(ExamDetails::InvalidDateException e)
    {
        cout << "Invalid DATE Exception catched !" << endl;
    }
    catch(ExamDetails::InvalidTimeException e)
    {
        cout << "Invalid TIME Exception catched !" << endl;
    }
    catch(ExamDetails::InvalidArgsException e)
    {
        cout << "Invalid ARGS Exception catched !" << endl;
    }

    cout << "If reached here, didnt crashed ! end of program..." << endl;

	return 0;
}