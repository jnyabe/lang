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

typedef int DataType;
typedef string DataKey;
typedef string DataValue;

// sequence container
typedef vector<DataType> Vector;
typedef array<DataType, num_ent> Array; // C++11
typedef deque<DataType> Deque;
typedef list<DataType> List;
typedef forward_list<DataType> ForwardList;

// key-value container with binary tree (red-black tree)
typedef set<DataKey> Set;
typedef multiset<DataKey> MultiSet;
typedef map<DataKey, DataValue> Map;
typedef multimap<DataKey, DataValue> MultiMap;

// key-value container with hash
typedef unordered_set<DataKey> UnorderedSet;                       // C++11
typedef unordered_multiset<DataKey> UnorderedMultiSet;             // C++11
typedef unordered_map<DataKey, DataValue> UnorderedMap;            // C++11
typedef unordered_multimap<DataKey, DataValue> UnorderedMultiMap;  // C++11

// container adapter
typedef stack<DataType> Stack;
typedef queue<DataType>     Queue;
typedef priority_queue<DataType> PriorityQueue;

struct Containers
{
	Vector v;
	Array  a;
	Deque  d;
	List   l;
	ForwardList fl;

	Set    s;
	MultiSet    ms;
	UnorderedSet us;
	UnorderedMultiSet ums;
	Map    m;
	MultiMap mm;
	UnorderedMap um;
	UnorderedMultiMap umm;

	Stack         st;
	Queue         q;
	PriorityQueue pq;
	
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
		containers.v.push_back(value);
		containers.a[i] = value;
		containers.d.push_back(value);
		containers.l.push_back(value);
		containers.fl.push_front(value);

		containers.st.push(value);
		containers.q.push(value);
		containers.pq.push(value);		
	}
	
	for(int i=0; i < 10; i++)
	{
		int value = i % 5;
		string key = std::to_string(value);
		string val = "v_" + key;
		containers.s.insert(key);
		containers.ms.insert(key);
		containers.us.insert(key);
		containers.ums.insert(key);
		containers.m[key] = val;
		containers.mm.insert(make_pair(key, val));
		containers.um.insert(make_pair(key, val));
		containers.umm.insert(make_pair(key, val));
	}
}

void test_size(Containers &containers)
{
	printf("------------- size() API ----------------\n");

	size("vector", containers.v);
	size("array", containers.a);
	size("deque", containers.d);
	size("list", containers.l);
	printf("*) forward_list: no size() method\n");
	size("set", containers.s);
	size("multiset", containers.ms);
	size("unordred_set", containers.us);
	size("unordred_multiset", containers.ums);
	
	size("map", containers.m);
	size("multimap", containers.mm);
	size("unordered_map", containers.um);
	size("unordered_multimap", containers.umm);	

	size("stack", containers.st);
	size("queue", containers.q);
	size("priority queue", containers.pq);
	printf("-----------------------------------------\n");
}

void test_empty(Containers &containers)
{
	isEmpty("vector", containers.v);
	isEmpty("array", containers.a);
	isEmpty("deque", containers.d);
	isEmpty("list", containers.l);
	isEmpty("forward_list", containers.fl);
	isEmpty("set", containers.s);
	isEmpty("multiset", containers.ms);
	isEmpty("unordered_set", containers.us);
	isEmpty("unordered_multiset", containers.ums);
	isEmpty("map", containers.m);
	isEmpty("multimap", containers.mm);
	isEmpty("unordered_map", containers.um);
	isEmpty("unordered_multimap", containers.umm);
	isEmpty("stack", containers.st);
	isEmpty("queue", containers.q);
	isEmpty("priority queue", containers.pq);
	printf("-----------------------------------------\n");
}

void dump(Containers &containers)
{
	printf("--------------- dump ------------------\n");

	dump("vector", containers.v);
	dump("array", containers.a);
	dump("deque", containers.d);
	dump("list", containers.l);
	dump("forward_list", containers.fl);  
	dump("set", containers.s);
	dump("multiset", containers.ms);
	dump("unordred_set", containers.us);
	dump("unordred_multiset", containers.ums);
	
	dump_keyval("map", containers.m);
	dump_keyval("multimap", containers.mm);
	dump_keyval("unordered_map", containers.um);
	dump_keyval("unordered_multimap", containers.umm);	

	dump_stack("stack", containers.st);
	dump_queue("queue", containers.q);
	dump_stack("priority queue", containers.pq);
	printf("-----------------------------------------\n");
}


void clear(Containers &containers)
{
	printf("--------------- clear ------------------\n");
	// Clear
	containers.v.clear();
	printf("*) array: no clear() method\n");
	containers.d.clear();
	containers.l.clear();
	containers.fl.clear();
	containers.s.clear();
	containers.ms.clear();
	containers.us.clear();
	containers.ums.clear();
	containers.m.clear();
	containers.mm.clear();
	containers.um.clear();
	containers.umm.clear();
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
