#include <iostream>
#include <string>

// Sequence containers
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

// Associative containers
#include <set>
#include <map>
//#include <multimap>

// Unordered associative containers
#include <unordered_set>
#include <unordered_map>
//#include <unordered_multimap>

// Container adapter
#include <stack>
#include <queue>
//#include <priority_queue>

using namespace std;

const int num_ent = 10;

struct Containers
{
	typedef int DataType;
	typedef string DataKey;
	typedef string DataValue;
	
	// Sequence container
	vector<DataType> vector;
	array<DataType, num_ent>  array; // C++11
	deque<DataType> deque;
	list<DataType> list;
	forward_list<DataType> forward_list; // C++11

	// Associative conatiner
	set<DataKey> set;
	multiset<DataKey> multiset;
	map<DataKey, DataValue> map;
	multimap<DataKey, DataValue> multimap;

	// Unordered Associative conatiner
	unordered_set<DataKey> unordered_set;                     // C++11
	unordered_multiset<DataKey> unordered_multiset;           // C++11
	unordered_map<DataKey, DataValue> unordered_map;          // C++11
	unordered_multimap<DataKey, DataValue> unordered_multimap;  // C++11

	// Container adapter
	stack<DataType> stack;
	queue<DataType>     queue;
	priority_queue<DataType> priority_queue;

};

template<class T>
void dump(string label, const T& container)
{
	if(20 - label.size() > 0)
		label += string(20-label.size(), ' ');

	cout << label << ": "; 
	for(const auto& i: container)
		cout << i << ",";	 
	cout << endl;			 
}

template<class T>
void dump_keyval(string label, const T& container)
{
	if(20 - label.size() > 0)
		label += string(20-label.size(), ' ');	

	cout << label << ": ";						
	for(const auto& i: container)
	{						
		cout << "(" << i.first << ",";		
		cout << i.second << ")" << ",";			
	}
	cout << endl;							
}

template<class T>
void dump_stack(string label, const T& container)
{
	T c = container;
	
	if(20 - label.size() > 0)
		label += string(20-label.size(), ' ');	

	cout << label << ": ";						
	while(!c.empty())
	{
		cout << c.top() << ",";
		c.pop();
	}
	cout << endl;							
}

template<class T>
void dump_queue(string label, const T& container)
{
	T c = container;
	
	if(20 - label.size() > 0)
		label += string(20-label.size(), ' ');	

	cout << label << ": ";						
	while(!c.empty())
	{
		cout << c.front() << ",";
		c.pop();
	}
	cout << endl;							
}

template<class T>
void isEmpty(string label, const T& container)
{
	if(20 - label.size() > 0)
		label += string(20-label.size(), ' ');	
	cout << label << ".empty()? : ";						
	cout << (container.empty()? "true":"false") << endl;
}

template<class T>
void size(string label, const T& container)
{
	if(20 - label.size() > 0)
		label += string(20-label.size(), ' ');	
	cout << label << ".size() : ";
	cout << container.size() << endl; 
}

void init(Containers &containers)
{
	// Insert data
	for(int i=0; i < 10; i++)
	{
		int value = i % 5;
		containers.vector.push_back(value);
		containers.array[i] = value;
		containers.deque.push_back(value);
		containers.list.push_back(value);
		containers.forward_list.push_front(value);

		containers.stack.push(value);
		containers.queue.push(value);
		containers.priority_queue.push(value);		
	}
	
	for(int i=0; i < 10; i++)
	{
		int value = i % 5;
		string key = std::to_string(value);
		string val = "v_" + key;
		containers.set.insert(key);
		containers.multiset.insert(key);
		containers.map[key] = val;
		containers.multimap.insert(make_pair(key, val));
		
		containers.unordered_set.insert(key);
		containers.unordered_multiset.insert(key);
		containers.unordered_map.insert(make_pair(key, val));
		containers.unordered_multimap.insert(make_pair(key, val));
	}
}

void test_size(Containers &containers)
{
	printf("------------- size() API ----------------\n");

	size("vector", containers.vector);
	size("array", containers.array);
	size("deque", containers.deque);
	size("list", containers.list);
	printf("*) forward_list: no size() method\n");
	size("set", containers.set);
	size("multiset", containers.multiset);
	size("map", containers.map);
	size("multimap", containers.multimap);
	
	size("unordred_set", containers.unordered_set);
	size("unordred_multiset", containers.unordered_multiset);
	size("unordered_map", containers.unordered_map);
	size("unordered_multimap", containers.unordered_multimap);	

	size("stack", containers.stack);
	size("queue", containers.queue);
	size("priority queue", containers.priority_queue);
	printf("-----------------------------------------\n");
}

void test_empty(Containers &containers)
{
	isEmpty("vector", containers.vector);
	isEmpty("array", containers.array);
	isEmpty("deque", containers.deque);
	isEmpty("list", containers.list);
	isEmpty("forward_list", containers.forward_list);
	isEmpty("set", containers.set);
	isEmpty("multiset", containers.multiset);
	isEmpty("map", containers.map);
	isEmpty("multimap", containers.multimap);
	isEmpty("unordered_set", containers.unordered_set);
	isEmpty("unordered_multiset", containers.unordered_multiset);
	isEmpty("unordered_map", containers.unordered_map);
	isEmpty("unordered_multimap", containers.unordered_multimap);
	isEmpty("stack", containers.stack);
	isEmpty("queue", containers.queue);
	isEmpty("priority queue", containers.priority_queue);
	printf("-----------------------------------------\n");
}

void dump(Containers &containers)
{
	printf("--------------- dump ------------------\n");

	dump("vector", containers.vector);
	dump("array", containers.array);
	dump("deque", containers.deque);
	dump("list", containers.list);
	dump("forward_list", containers.forward_list);  
	dump("set", containers.set);
	dump("multiset", containers.multiset);
	
	dump_keyval("map", containers.map);
	dump_keyval("multimap", containers.multimap);
	
	dump("unordred_set", containers.unordered_set);
	dump("unordred_multiset", containers.unordered_multiset);
	dump_keyval("unordered_map", containers.unordered_map);
	dump_keyval("unordered_multimap", containers.unordered_multimap);

	dump_stack("stack", containers.stack);
	dump_queue("queue", containers.queue);
	dump_stack("priority queue", containers.priority_queue);
	printf("-----------------------------------------\n");
}


void clear(Containers &containers)
{
	printf("--------------- clear ------------------\n");
	// Clear
	containers.vector.clear();
	printf("*) array: no clear() method\n");
	containers.deque.clear();
	containers.list.clear();
	containers.forward_list.clear();
	
	containers.set.clear();
	containers.multiset.clear();
	containers.map.clear();
	containers.multimap.clear();
	
	containers.unordered_set.clear();
	containers.unordered_multiset.clear();
	containers.unordered_map.clear();
	containers.unordered_multimap.clear();
	
	printf("*) stack: no clear() method\n");
	printf("*) queue: no clear() method\n");
	printf("*) priority_queue: no clear() method\n");
	printf("-----------------------------------------\n");	
}

int main(int argc, const char* argv[])
{
	Containers containers;

	init(containers);
	test_size(containers);
	test_empty(containers);
	dump(containers);	
	clear(containers);
	dump(containers);	
	return 0;
}
