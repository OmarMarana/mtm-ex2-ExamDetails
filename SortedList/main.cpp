#include "SortedList.h"
using namespace mtm;
using namespace std;


int main()
{
    SortedList list = SortedList();

    list.insert(5);
    list.insert(4);
    list.insert(-2);
    list.insert(-1);

    list.print();

    SortedList list2(list);

    cout << "list 2 prints: \n";
    list2.print();
    list2.insert(69);
    list2.print();
    
    return 0;
}
