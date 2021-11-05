
#include <memory>
#include <list>
#include "linked_list.h"
#include <string>

int main()
{
	List<int> lst;
	//lst.push_back(5);
	//lst.push_back(10);
	//lst.push_back(22);

	int sz = lst.getSize();
	{
		//auto node1 = std::make_unique<ListNode<std::string>>("first node");
		//auto node2 = std::make_unique<ListNode<std::string>>("second node", node1);
		//auto node2 = std::make_unique<ListNode<std::string>>("second node", node1);
		//auto node3 = std::make_unique<ListNode<std::string>>("third node", node2);
	}

	//std::cout << lst[2] << std::endl;
	unsigned int numbersCount;
	std::cin >> numbersCount;
	std::cout << "voila" << std::endl;
	for (unsigned int i = 0; i < numbersCount; i++)
	{
		lst.push_back(rand() % 10);
	}

	lst.set_additional_link(3, 6);

	for (unsigned int i = 0; i < lst.getSize(); i++)
	{
		std::cout << lst[i] << std::endl;
	}

	std::cout << "pop front" << std::endl;
	lst.pop_front();

	for (unsigned int i = 0; i < lst.getSize(); i++)
	{
		std::cout << lst[i] << std::endl;
	}

	std::cout << "clear" << std::endl;
	lst.clear();

	for (unsigned int i = 0; i < lst.getSize(); i++)
	{
		std::cout << lst[i] << std::endl;
	}
//	List<std::string> list(node1);
	return 0;
}