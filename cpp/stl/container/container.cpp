#include "container.h"

using namespace std;

int Container::Init(int num)
{
	Clear();
	// Insert data
	for(int i=0; i < num; i++)
	{
		vector.push_back(i);
		array[i % array.size()] = i;
		deque.push_back(i);
		list.push_back(i);
		forward_list.push_front(i);
		stack.push(i);
		queue.push(i);
		priority_queue.push(i);		
	}
	
	for(int i=0; i < num; i++)
	{
		string key = std::to_string(i);
		string val(3, 'a' + (i % 26));
		set.insert(key);
		multiset.insert(key);
		map[key] = val;
		multimap.insert(make_pair(key, val));
		
		unordered_set.insert(key);
		unordered_multiset.insert(key);
		unordered_map.insert(make_pair(key, val));
		unordered_multimap.insert(make_pair(key, val));
	}
	return 0;
}

int Container::Size(void)
{
	int ret = 0;
	printf("------------- size() API ----------------\n");
	size("vector", vector);
	size("array", array);
	size("deque", deque);
	size("list", list);
	printf("*) forward_list: no size() method\n");
	size("set", set);
	size("multiset", multiset);
	size("map", map);
	size("multimap", multimap);
	
	size("unordred_set", unordered_set);
	size("unordred_multiset", unordered_multiset);
	size("unordered_map", unordered_map);
	size("unordered_multimap", unordered_multimap);	

	size("stack", stack);
	size("queue", queue);
	size("priority queue", priority_queue);
	printf("-----------------------------------------\n");
	return ret;
}

int Container::Empty(void)
{
	int ret = 0;
	isEmpty("vector", vector);
	isEmpty("array", array);
	isEmpty("deque", deque);
	isEmpty("list", list);
	isEmpty("forward_list", forward_list);
	isEmpty("set", set);
	isEmpty("multiset", multiset);
	isEmpty("map", map);
	isEmpty("multimap", multimap);
	isEmpty("unordered_set", unordered_set);
	isEmpty("unordered_multiset", unordered_multiset);
	isEmpty("unordered_map", unordered_map);
	isEmpty("unordered_multimap", unordered_multimap);
	isEmpty("stack", stack);
	isEmpty("queue", queue);
	isEmpty("priority queue", priority_queue);
	printf("-----------------------------------------\n");
	return ret;	
}

int Container::Dump(void)
{
	int ret = 0;
	printf("--------------- dump ------------------\n");

	dump("vector", vector);
	dump("array", array);
	dump("deque", deque);
	dump("list", list);
	dump("forward_list", forward_list);  
	dump("set", set);
	dump("multiset", multiset);
	
	dump_keyval("map", map);
	dump_keyval("multimap", multimap);
	
	dump("unordred_set", unordered_set);
	dump("unordred_multiset", unordered_multiset);
	dump_keyval("unordered_map", unordered_map);
	dump_keyval("unordered_multimap", unordered_multimap);

	dump_stack("stack", stack);
	dump_queue("queue", queue);
	dump_stack("priority queue", priority_queue);
	printf("-----------------------------------------\n");
	return ret;
}


int Container::Clear(void)
{
	int ret = 0;
	// printf("--------------- clear ------------------\n");
	// Clear
	vector.clear();
	// printf("*) array: no clear() method\n");
	deque.clear();
	list.clear();
	forward_list.clear();
	
	set.clear();
	multiset.clear();
	map.clear();
	multimap.clear();
	
	unordered_set.clear();
	unordered_multiset.clear();
	unordered_map.clear();
	unordered_multimap.clear();
	
	// printf("*) stack: no clear() method\n");
	// printf("*) queue: no clear() method\n");
	// printf("*) priority_queue: no clear() method\n");
	
	// repeat pop until it becomes emtpty
	while(!stack.empty()) stack.pop(); 
	while(!queue.empty()) queue.pop(); 
	while(!priority_queue.empty()) priority_queue.pop(); 
	

	// printf("-----------------------------------------\n");
	return ret;
}
	
int Container::TestInsert(void)
{
	Clear();
	printf("Back\n");
	// Insert data (back)
	test_push_back("vector", vector, m_num_test);
	// test_push_back("array", array, m_num_test);
	test_push_back("deque", deque, m_num_test);
	test_push_back("list", list, m_num_test);
	// test_push_back("forward_list", forward_list);

	Clear();
	printf("Front\n");
	// Insert data (front)
	// test_push_front("vector", vector, m_num_test);
	// test_push_front("array", array, m_num_test);
	test_push_front("deque", deque, m_num_test);
	test_push_front("list", list, m_num_test);
	test_push_front("forward_list", forward_list, m_num_test);

	Clear();
	printf("Other\n");
	
#if 0
	// Insert data (middle)
	for(int i=0; i < m_num_test; i++) vector.push_back(i);
	// for(int i=0; i < m_num_test; i++) array.push_front(i);
	for(int i=0; i < m_num_test; i++) deque.push_front(i);
	for(int i=0; i < m_num_test; i++) list.push_front(i);
	for(int i=0; i < m_num_test; i++) forward_list.push_front(i);
	// for(int i=0; i < m_num_test; i++) set.insert(i);
	// for(int i=0; i < m_num_test; i++) multiset.insert(i);
#endif	

	return 0;	
}

int Container::TestErase(void)
{
	Init(m_num_test);
	printf("%s\n", __FUNCTION__);
	printf("1)Back\n");
	// Erase data (back)
	
	test_pop_back("vector", vector, m_num_test);
	// test_push_back("array", array, m_num_test);
	test_pop_back("deque", deque, m_num_test);
	test_pop_back("list", list, m_num_test);
	// test_pop_back("forward_list", forward_list);

	Init(m_num_test);
	printf("2)Front\n");
	// Erase data (front)
	// test_pop_front("vector", vector, m_num_test);
	// test_pop_front("array", array, m_num_test);
	test_pop_front("deque", deque, m_num_test);
	test_pop_front("list", list, m_num_test);
	test_pop_front("forward_list", forward_list, m_num_test);

	Init(m_num_test);
	printf("3)Other\n");
	// Erase data (middle)
	for(int i=0; i < m_num_test; i++) vector.push_back(i);
	// for(int i=0; i < m_num_test; i++) array.push_front(i);
	for(int i=0; i < m_num_test; i++) deque.push_front(i);
	for(int i=0; i < m_num_test; i++) list.push_front(i);
	for(int i=0; i < m_num_test; i++) forward_list.push_front(i);
	// for(int i=0; i < m_num_test; i++) set.insert(i);
	// for(int i=0; i < m_num_test; i++) multiset.insert(i);	
	return 0;
}

int Container::TestAccess(void)
{
	Init(m_num_test);
	printf("-- Random Access --\n");
	test_random_access("vector", vector, m_num_test);
	// test_random_access("array",  array, m_num_test);
	test_random_access("deque", deque, m_num_test);
	// test_random_access_back("list", list, m_num_test);
	// test_random_access_back("forward_list", forward_list);
	// test_random_access("set", set, m_num_test);
	// test_random_access("multiset", multiset, m_num_test);
	// test_random_access("map", map, m_num_test);
	// test_random_access("multimap", multmap, m_num_test);
	// test_random_access("unordered_set", unordered_set, m_num_test);
	// test_random_access("unordered_multiset", unordered_multiset, m_num_test);
	// test_random_access("unordered_map", unordered_map, m_num_test);
	// test_random_access("unordered_multimap", unordered_multimap, m_num_test);
	
	return 0;
}


int Container::TestLookFor(void)
{
	Init(m_num_test);
	printf("[Look for]\n");
	test_look_for("vector", vector, m_num_test);
	// test_look_for("array",  array, m_num_test);
	test_look_for("deque", deque, m_num_test);
	// test_look_for_back("list", list, m_num_test);
	// test_look_for_back("forward_list", forward_list);
	// test_look_for("set", set, m_num_test);
	// test_look_for("multiset", multiset, m_num_test);
	// test_look_for("map", map, m_num_test);
	// test_look_for("multimap", multmap, m_num_test);
	// test_look_for("unordered_set", unordered_set, m_num_test);
	// test_look_for("unordered_multiset", unordered_multiset, m_num_test);
	// test_look_for("unordered_map", unordered_map, m_num_test);
	// test_look_for("unordered_multimap", unordered_multimap, m_num_test);
		
	return 0;
}

int Container::Test(void)
{
	for(int i=0; i< 10; i++)
	{
		Init(100);
	}
	
	return 0;
}
