#ifndef _SS_BASE_H_
#define _SS_BASE_H_

#include <string>

class SSBase
{
private:
	int m_seed; // random seed
	
protected:
	
	enum SSInfoType {
		SS_INFO_TYPE_NAME = 0,
		SS_INFO_TYPE_BEST_TIME_COMPLEXITTY,
		SS_INFO_TYPE_WORST_TIME_COMPLEXITTY,
		SS_INFO_TYPE_AVERAGE_TIME_COMPLEXITTY,
		SS_INFO_TYPE_WORST_SPACE_COMPLEXITTY,
		SS_INFO_TYPE_MAX,
	};
	std::string m_info[SS_INFO_TYPE_MAX];

public:
	/// @Brief Default constructor
	SSBase():m_seed(10) {}

	/// @Brief Destructor
	virtual ~SSBase() {}

	/// @brief Search 'pattern' string in 'text' string
	/// @param[in] text string to be searched from
	/// @param[in] pattern string to be searched
	/// @retval index of pattern (if found)
	/// @retval -1 (if not found)
	virtual int Search(const char* text, const char* pattern) const = 0;
	
	/// @brief Run string search demo
	/// @param[in,out] array to be sorted
	/// @retval 0 Success
	/// @retval Nagative number Error
	int Run(int argc, const char* argv[]) const;

	/// @brief show brief descrption of the string search alogirhm
	void Help(void) const;

};

#endif /* _SS_BASE_H_ */
