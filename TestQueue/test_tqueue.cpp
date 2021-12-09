#include "../mp2-lab4-queue/mp2-lab4-queue/TQueue.h"

#include "gtest.h"

TEST(TQueue, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(TQueue<int> s(5));
}

TEST(TQueue, throws_when_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(TQueue<int> s(-5));
}

//TEST(TQueue, can_create_copied_stack)
//{
//  TQueue<int> m(5);
//  ASSERT_NO_THROW(TQueue<int> m1(m));
//}

//TEST(TQueue, copied_stack_is_equal_to_source_one)
//{
//	TQueue<int> m(5);
//	TQueue<int> mm(m);
//	EXPECT_EQ(m, mm);
//}

//TEST(TQueue, copied_stack_has_its_own_memory)
//{
//	TQueue<int> m(5);
//	TQueue<int> mm(m);
//	EXPECT_NE(&m, &mm);
//}

TEST(TQueue, can_assign_stack_to_itself)
{
	TQueue<int> m(5);
	ASSERT_NO_THROW(m = m);
}

TEST(TQueue, can_get_maxsize)
{
	TQueue<int> m(5);
	EXPECT_EQ(m.GetMaxSize(), 5);
}

TEST(TQueue, can_get_size)
{
	TQueue<int> m(5);
	m.Push(0);
	EXPECT_EQ(m.GetSize(), 1);
}

TEST(TQueue, can_push_if_queue_isnt_full)
{
	TQueue<int> m(5);
	m.Push(1);

	EXPECT_EQ(m.Pop(), 1);
}

TEST(TQueue, cant_push_if_stack_is_full)
{
	TQueue<int> m(5);
	for(int i = 0; i < 5; i++)
		m.Push(1);
	ASSERT_ANY_THROW(m.Push(1));
}

TEST(TQueue, can_pop_if_stack_isnt_empty)
{
	TQueue<int> m(5);
	for (int i = 0; i < 5; i++)
		m.Push(1);
	EXPECT_EQ(m.Pop(), 1);
}

TEST(TQueue, cant_pop_if_stack_is_empty)
{
	TQueue<int> m(5);
	ASSERT_ANY_THROW(m.Pop());
}

TEST(TQueue, jhkj)
{
	TQueue<int> m(5);
	for (int i = 0; i < 5; i++)
		m.Push(i);
	m.Pop();
	m.Push(5);
	EXPECT_EQ(1, m.GetTail());
}

