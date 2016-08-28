#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <vector>
#include <string>

class Array
{
private:
	std::vector<int> m_array;
	
public:
	Array();
	Array(int size);
	Array(const Array& array);
	virtual ~Array();
	void Shuffle(void);
	void Shuffle(int seed);	
	void Swap(int left, int right);
	void Print(std::string label) const;
	inline size_t Size(void) const { return m_array.size(); }
	inline int operator[](std::size_t index) const { return m_array[index];}
	inline int& operator[](std::size_t index) { return m_array[index];}
	Array& operator=(const Array& array);
};

#endif /* _SORT_UTIL_H_ */
