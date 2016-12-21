#include "List.h"
#include <gtest.h>

///////////////////////////////////////////////////////////////////////
//тесты для списка
TEST(TList, can_create_list)
{
	ASSERT_NO_THROW(_List<char> l);
}

TEST(TList, can_add_node_in_empty_list)
{
	_List<char> l;
	ASSERT_NO_THROW(l.add_el_in_head('a'));
}

TEST(Tlist, cant_del_from_empty_list)
{
	_List<char> l;

	EXPECT_ANY_THROW(l.del_el_fr_head());
	EXPECT_ANY_THROW(l.del_el_fr_tail());
	//EXPECT_ANY_THROW(l.del_node()
}

TEST(Tlist, cant_find_ptr_in_empty_list)
{
	_List<char> l;
	ASSERT_ANY_THROW(l.find_ptr('b'));
}

TEST(Tlist, can_find_ptr)
{
	_List<char> l;
	l.add_el_in_tail('a');
	ASSERT_NO_THROW(l.find_ptr('a'));

}

TEST(Tlist, find_is_correct)
{
	_List<char> l;
	l.add_el_in_tail('a');
	l.add_el_in_tail('b');

	_Node<char>* n = l.find_ptr('b');
	EXPECT_EQ('b', n->data);

}

TEST(Tlist, list_is_correctly_empty)
{
	_List<char> l;
	l.add_el_in_tail('a');
	l.del_el_fr_tail();
	EXPECT_EQ(l.GetSize(), 0);

}

TEST(TList, can_add_node_in_tail)
{
	_List<char> l;
	l.add_el_in_tail('a');
	EXPECT_EQ('a', l.viewData(l.find_ptr('a')));
}
TEST(Tlist, can_del_node_from_tail)
{
	_List<char> l;
	l.add_el_in_tail('a'); 
	l.add_el_in_tail('b');
	l.del_el_fr_tail();
	EXPECT_EQ('a', l.viewData(l.find_ptr('a')));
}

TEST(TList, can_add_node_in_head)
{
	_List<char> l;
	l.add_el_in_head('a');
	EXPECT_EQ('a', l.viewData(l.find_ptr('a')));
}

TEST(Tlist, can_del_node_from_head)
{
	_List<char> l;
	l.add_el_in_head('a');
	l.add_el_in_head('b');
	EXPECT_EQ('b', l.del_el_fr_head());
}

TEST(Tlist, can_add_node_after_ptr)
{
	_List<char> l;
	l.add_el_in_head('a');
	_Node<char>* ptr = l.find_ptr('a');
	l.add_node(ptr, 'b');
	EXPECT_EQ('b', l.viewData(l.find_ptr('b')));

}


//////////////////////////////////////////////////////////////////////////
//тесты для стека

TEST(TStack, can_create_stack)
{
	ASSERT_NO_THROW(_Stack<int> st);
}

TEST(TStack, push_elem_correctly)
{
	_Stack<int> st;
	st.push(2);
	ASSERT_TRUE(st.view_top() == 2);
}



TEST(TStack, pop_elem_correctly)
{
	_Stack<int> st;
	st.push(2);
	ASSERT_TRUE(st.pop() == 2);

}

TEST(TStack, cant_pop_elem_from_emp_st)
{
	_Stack<int> st;
	ASSERT_ANY_THROW(st.pop());
}

TEST(TStack, stack_isnt_empty)
{
	_Stack<int> st;
	st.push(1);
	ASSERT_EQ(st.is_stack_empty(), 0);
}

TEST(TStack, clear_stack_correctly)
{
	_Stack<int> st;
	st.push(2);
	st.pop();
	ASSERT_TRUE(st.is_stack_empty() == 1);
}

