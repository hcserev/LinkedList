
#include <memory>
#include <list>
#include "linked_list.h"
#include <string>

int main()
{
	List<int> lst;

	unsigned int numbersCount;
	std::cin >> numbersCount;
	std::cout << "voila" << std::endl;
	for (unsigned int i = 0; i < numbersCount; i++)
	{
		lst.push_back(rand() % 10);
	}

	lst.set_additional_link(3, 6);

	for (unsigned int i = 0; i < lst.get_size(); i++)
	{
		std::cout << lst[i] << std::endl;
	}

	std::cout << "pop front" << std::endl;
	lst.pop_front();

	for (unsigned int i = 0; i < lst.get_size(); i++)
	{
		std::cout << lst[i] << std::endl;
	}

	std::cout << "clear" << std::endl;
	lst.clear();

	for (unsigned int i = 0; i < lst.get_size(); i++)
	{
		std::cout << lst[i] << std::endl;
	}

	return 0;
}