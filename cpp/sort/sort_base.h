#ifndef _SORT_BASE_H_
#define _SORT_BASE_H_

#include "array.h"
#include <string>

class SortBase
{
private:
	int m_seed; // random seed
	
protected:
	
	enum SortInfoType {
		SORT_INFO_TYPE_NAME = 0,
		SORT_INFO_TYPE_BEST_TIME_COMPLEXITTY,
		SORT_INFO_TYPE_WORST_TIME_COMPLEXITTY,
		SORT_INFO_TYPE_AVERAGE_TIME_COMPLEXITTY,
		SORT_INFO_TYPE_MAX,
	};
	std::string m_info[SORT_INFO_TYPE_MAX];
	
public:
	/// @Brief Default constructor
	SortBase():m_seed(10) {}

	/// @Brief Destructor
	virtual ~SortBase() {}

	/// @brief Sort the denoted array
	/// @param[in,out] array to be sorted
	/// @retval 0 Success
	/// @retval Nagative number Error
	virtual int Sort(Array& array) const = 0;

	/// @brief Test sort alogrithm with the denoted array
	/// @param[in,out] array to be sorted
	/// @retval 0 Success
	/// @retval Nagative number Error
	virtual void Test(Array& array) const;

	/// @brief Run sorting demo
	/// @param[in,out] array to be sorted
	/// @retval 0 Success
	/// @retval Nagative number Error
	int Run(int argc, const char* argv[]) const;

	/// @brief Check if the denoted array is sorted
	/// @param[in] array array to be checked
	/// @retval true sorted
	/// @retval false unsorted
	static bool IsSorted(const Array& array);

	/// @brief show brief descrption of the sort alogirhm
	void Help(void) const;
};

#endif /* _SORT_BASE_H_ */
