#include "container.h"

using namespace std;

int Container::Init(void)
{
	// Insert data
	for(int i=0; i < 10; i++)
	{
		int value = i % 5;
		vector.push_back(value);
		array[i] = value;
		deque.push_back(value);
		list.push_back(value);
		forward_list.push_front(value);

		stack.push(value);
		queue.push(value);
		priority_queue.push(value);		
	}
	
	for(int i=0; i < 10; i++)
	{
		int value = i % 5;
		string key = std::to_string(value);
		string val(3, 'a' + value);
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

int Container::TestSize(void)
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

int Container::TestEmpty(void)
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
	printf("--------------- clear ------------------\n");
	// Clear
	vector.clear();
	printf("*) array: no clear() method\n");
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
	
	printf("*) stack: no clear() method\n");
	printf("*) queue: no clear() method\n");
	printf("*) priority_queue: no clear() method\n");
	printf("-----------------------------------------\n");
	return ret;
}
	
int Container::TestInsert(void)
{
	int num = 100000;
	printf("-- Insert (Back) --\n");
	// Insert data (back)
	test_push_back("vector", vector, num);
	// test_push_back("array", array, num);
	test_push_back("deque", deque, num);
	test_push_back("list", list, num);
	// test_push_back("forward_list", forward_list);

	printf("-- Insert (Front) --\n");
	// Insert data (front)
	// test_push_front("vector", vector, num);
	// test_push_front("array", array, num);
	test_push_front("deque", deque, num);
	test_push_front("list", list, num);
	test_push_front("forward_list", forward_list, num);

	printf("-- Insert (Other) --\n");
	// Insert data (middle)
	for(int i=0; i < num; i++) vector.push_back(i);
	// for(int i=0; i < num; i++) array.push_front(i);
	for(int i=0; i < num; i++) deque.push_front(i);
	for(int i=0; i < num; i++) list.push_front(i);
	for(int i=0; i < num; i++) forward_list.push_front(i);
	// for(int i=0; i < num; i++) set.insert(i);
	// for(int i=0; i < num; i++) multiset.insert(i);
	

	return 0;	
}

int Container::TestAccess(void)
{
	Clear();
	
	return 0;
}

int Container::TestErase(void)
{
	Clear();	
	return 0;
}
int Container::TestFind(void)
{
	Clear();
	return 0;
}
