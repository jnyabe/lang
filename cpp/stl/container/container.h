#ifndef __CONTAINER_H__
#define __CONTAINER_H__

#include <chrono>
#include <string>

class Container
{
protected:
	struct ElapsedTime
	{
		std::chrono::system_clock::time_point start;
		std::chrono::system_clock::time_point end;
	};

	void start(ElapsedTime& etime) const;
	void end(ElapsedTime& etime) const;
	std::string format(const ElapsedTime& etime) const;
	
public:
	typedef int DataKey;
	typedef std::string DataValue;
	
	Container(){}
	
	virtual ~Container() {}

	virtual int Size() const = 0;

	// insert any point
	virtual void Insert(const DataKey &key, const DataValue &value) = 0;

	// erase any poinrt
	virtual void Erase(const DataKey &key) = 0;

	virtual void Dump(void) const = 0;
};

#endif /* __CONTAINER_H__ */
