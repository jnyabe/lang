#ifndef __CONTAINER_H__
#define __CONTAINER_H__

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

#include <chrono>


class Container
{
private:
	static const int num_ent = 10;
	typedef int DataType;
	typedef std::string DataKey;
	typedef std::string DataValue;
	
	// Sequence container
	std::vector<DataType> vector;
	std::array<DataType, num_ent>  array; // C++11
	std::deque<DataType> deque;
	std::list<DataType> list;
	std::forward_list<DataType> forward_list; // C++11

	// Associative conatiner
	std::set<DataKey> set;
	std::multiset<DataKey> multiset;
	std::map<DataKey, DataValue> map;
	std::multimap<DataKey, DataValue> multimap;

	// Unordered Associative conatiner
	std::unordered_set<DataKey> unordered_set;                     // C++11
	std::unordered_multiset<DataKey> unordered_multiset;           // C++11
	std::unordered_map<DataKey, DataValue> unordered_map;          // C++11
	std::unordered_multimap<DataKey, DataValue> unordered_multimap;  // C++11

	// Container adapter
	std::stack<DataType> stack;
	std::queue<DataType>     queue;
	std::priority_queue<DataType> priority_queue;

	std::chrono::system_clock::time_point getTime();

	template<class T>
	void dump(std::string label, const T& container)
	{
		if(20 - label.size() > 0)
			label += std::string(20-label.size(), ' ');
		std::cout << label << "=[";
		for(const auto& i: container)
			std::cout << i << ",";
		std::cout << "]" << std::endl;		
	}

	template<class T>
	void dump_keyval(std::string label, const T& container)
	{
		if(20 - label.size() > 0)
			label += std::string(20-label.size(), ' ');
		std::cout << label << "=[";
		for(const auto& i: container)
		{
			std::cout << "(" << i.first << ",";
			std::cout << i.second << ")" << ",";
		}
		std::cout << "]" << std::endl;		
	}

	template<class T>
	void dump_stack(std::string label, const T& container)
	{
		T c = container;

		if(20 - label.size() > 0)
			label += std::string(20-label.size(), ' ');

		std::cout << label << "=[";
		while(!c.empty())
		{
			std::cout << c.top() << ",";
			c.pop();
		}
		std::cout << "]" << std::endl;		
	}
	

	template<class T>
	void dump_queue(std::string label, const T& container)
	{
		T c = container;

		if(20 - label.size() > 0)
			label += std::string(20-label.size(), ' ');

		std::cout << label << "=[";
		while(!c.empty())
		{
			std::cout << c.front() << ",";
			c.pop();
		}
		std::cout << "]" << std::endl;
	}
	template<class T>
	void isEmpty(std::string label, const T& container)
	{
		if(20 - label.size() > 0)
			label += std::string(20-label.size(), ' ');
		std::cout << label << ".empty()? : ";
		std::cout << (container.empty()? "true":"false") << std::endl;
	}

	template<class T>
	void size(std::string label, const T& container)
	{
		if(20 - label.size() > 0)
			label += std::string(20-label.size(), ' ');
		std::cout << label << ".size() : ";
		std::cout << container.size() << std::endl;
	}

public:
	Container() {}
	virtual ~Container(){}
	int Init(void);
	int TestSize(void);
	int TestEmpty(void);
	int Dump(void);
	int Clear(void);
};

#endif /* __CONTAINER_H__ */
