#ifndef __CONTAINER_H__
#define __CONTAINER_H__

class Container
{
private:
	
public:
	typedef int DataType;
	Container() {}
	
	virtual ~Container() {}

	virtual int Size() const = 0;
	// random acccess
	virtual DataType Get(int n) const = 0;

	// acccess head and tail
	virtual DataType Front(void) const = 0;
	virtual DataType Back(void) const = 0;

	virtual DataType& operator[](int n) = 0;
	
	// insert head and tail
	virtual void PushBack(DataType n) = 0;
	virtual void PushFront(DataType n) = 0;

	// insert any point
	virtual void Insert(int idx, DataType n) = 0;

	// delete head and tail
	virtual void PopBack(void) = 0;
	virtual void PopFront(void) = 0;

	// delete any poinrt
	virtual void Delete(int idx) = 0;

	virtual void Dump(void) const = 0;
};

#endif /* __CONTAINER_H__ */
