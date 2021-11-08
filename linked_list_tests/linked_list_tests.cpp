#include <gtest/gtest.h>
#include <../linked_list.h>

TEST(LinkedListTest, DefaultConstructorSizeTest)
{
	List<int> list;
	EXPECT_TRUE(list.get_size() == 0);
}
TEST(LinkedListTest, PushBackTest)
{
	List<int> list;
	list.push_back(5);
	EXPECT_TRUE(list.get_value() == 5);
}

TEST(LinkedListTest, PushBackSizeTest)
{
	List<double> list;
	list.push_back(5.2);
	list.push_back(6.1);
	EXPECT_TRUE(list.get_size() == 2);
}
TEST(LinkedListTest, CopyTest1)
{
	List<int> list1;
	list1.push_back(4);
	list1.push_back(3);
	list1.set_additional_link(0, 1);
	list1.set_additional_link(1, 0);
	List<int> list2(list1);

	EXPECT_TRUE(list2.get_value() == 4);
}
