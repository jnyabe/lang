#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_

#include "sort_base.h"

/// @brief Implementation of Quick sort algorithm
class QuickSort: public SortBase
{
private:
	/// @brief quick sort
	/// @param[in,out] array array to be sorted
	/// @param[in] left index of left end of array
	/// @param[in] right index of left end of array
	/// @retval 0 Success
	int sort0(Array &array, int left, int right) const;
	
	/// @brief Simple quick sort
	/// @param[in,out] array array to be sorted
	/// @param[in] left index of left end of array
	/// @param[in] right index of left end of array
	/// @retval 0 Success
	/// @note Quicksort by C. A. R. Hoare
	int sort1(Array &array, int left, int right) const;

	/// @brief Better quick sort imporved by Bob Sedgewick
	/// @param[in,out] array array to be sorted
	/// @param[in] left index of left end of array
	/// @param[in] right index of left end of array
	/// @retval 0 Success
	int sort2(Array &array, int left, int right) const;

	/// @brief Beter quick sort
	/// @param[in,out] array array to be sorted
	/// @param[in] left index of left end of array
	/// @param[in] right index of left end of array
	/// @retval 0 Success
	int sort3(Array &array, int left, int right) const;

	/// @brief Quick sort
	/// @param[in,out] array array to be sorted
	/// @param[in] left index of left end of array
	/// @param[in] right index of left end of array
	/// @retval 0 Success
	int sort4(Array &array, int left, int right) const;

	enum AlgorithmType
		{
			AlgorithmType_0,
			AlgorithmType_Lomuto,
			AlgorithmType_Sedgewick,
			AlgorithmType_3,
		};

	AlgorithmType m_type;
public:
	/// @brief Default constructor
	QuickSort()
	{
		const char* type[] =
			{
				"?",
				"Lomuto",
				"Sedgewick",
				"?"
			};
		m_type = AlgorithmType_Sedgewick;
		m_info[SORT_INFO_TYPE_NAME] = "Quick Sort";
		m_info[SORT_INFO_TYPE_NAME] += type[m_type];
		m_info[SORT_INFO_TYPE_BEST_TIME_COMPLEXITTY]    = "O(N log(N))";
		m_info[SORT_INFO_TYPE_WORST_TIME_COMPLEXITTY]   = "O(N^2)";
		m_info[SORT_INFO_TYPE_AVERAGE_TIME_COMPLEXITTY] = "O(N log(N))";
	}

	/// @brief Destructor
	virtual ~QuickSort() {}

	
	virtual int Sort(Array &array) const;
};

#endif /* _QUICK_SORT_H_ */
