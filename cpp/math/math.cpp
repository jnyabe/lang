#include "math.h"

int Math::Factorial(int n)
{
	return (n==1)? 1: n * Factorial(n-1);
}


ArrayList Math::Permutation(const Array &array, int k)
{
	ArrayList result;
	if(k == 1)
	{
		for(const auto& e: array)
		{
			Array tmp;
			tmp.push_back(e);
			result.push_back(tmp);
		}
		return result;
	} 

	for(const auto& e: array)
	{
		Array a2 = array;
		Array::iterator it = std::remove_if(a2.begin(), a2.end(),
											[&e](int x) { return x == e;});
		a2.erase(it, a2.end());
		ArrayList list2 = Permutation(a2, k-1);
		for(auto& l: list2)
		{
			l.insert(l.begin(), e);
		}
		result.splice(result.end(), std::move(list2));
	}
	return result;
}


int Math::NumOfPermutation(int n, int k)
{
	return Factorial(n) / Factorial(n -k);
}


ArrayList Math::Combination(const Array &array, int k)
{
	ArrayList result;
	return result;
}

int Math::NumOfCombination(int n, int k)
{
	return NumOfPermutation(n, k) / Factorial(k);
}
	

