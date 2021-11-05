
#include <memory>
#include <list>
#include "linked_list.h"
#include <string>

int main()
{
	List<int> lst;

	unsigned int numbersCount = 6;
	//std::cin >> numbersCount;
	std::cout << "voila" << std::endl;
	for (unsigned int i = 0; i < numbersCount; i++)
	{
		lst.push_back(rand() % 10);
	}

	lst.set_additional_link(0, 3);
	lst.set_additional_link(1, 4);
	lst.set_additional_link(2, 1);
	lst.set_additional_link(3, 5);
	lst.set_additional_link(4, 0);
	lst.set_additional_link(5, 4);

	for (unsigned int i = 0; i < lst.get_size(); i++)
	{
		lst[i];
	}

	std::unique_ptr<ICopyAlghorithm> copyAlgo(new CopyUsingVectors);
	List<int> lst2(lst);


	std::cout << "list2:" << std::endl;
	for (unsigned int i = 0; i < lst.get_size(); i++)
	{
		lst2[i];
	}

	return 0;
}