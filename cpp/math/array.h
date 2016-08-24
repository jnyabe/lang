#ifndef _ARRAY_H_
#define _ARRAY_H_


#include <list>
#include <vector>

typedef std::vector<int> Array;
typedef std::list<Array> ArrayList;


void print(const Array& a);
void print(const ArrayList& list);

#endif /* _ARRAY_H_ */
