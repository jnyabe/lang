#ifndef _MATH_H_
#define _MATH_H_

#include "array.h"

class Math
{
public:
	/// @brief Get factorial (n!)
	/// @param[in] n
	/// @return n!
	static int Factorial(int n);

	/// @brief Get permutation for the denoted array
	/// @param[in] array array contains items to be selected
	/// @param[in] k number of items to be selected
	/// @return list of all permutation
	static ArrayList Permutation(const Array &array, int k);

	/// @brief Get number of permutation for the denoted by n and k
	/// @param[in] n number of items to be selected
	/// @param[in] k number of items to be selected
	/// @return number of permutation
	static int NumOfPermutation(int n, int k);

	/// @brief Get combination for the denoted array
	/// @param[in] array array contains items to be selected
	/// @param[in] k number of items to be selected	
	/// @return list of all combination
	static ArrayList Combination(const Array &array, int k);

	/// @brief Get number of combination for the denoted array

	/// @brief Get number of combination denoted by n and r
	/// @param[in] n number of items to be selected
	/// @param[in] k number of items to be selected	
	/// @return number of combination
	static int NumOfCombination(int n, int k);
	
};
#endif /* _MATH_H_ */
