
#include <memory>
#include <list>
#include "linked_list.h"

int main()
{
	std::list<int> l1;
	MyList<int> l2;
	MyList<int> l3(44);
	l2.setHeadVal(54);
	int d = l2.getHeadVal();
	return 0;
}