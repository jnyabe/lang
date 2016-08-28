#ifndef _SS_BASE_H_
#define _SS_BASE_H_

#include <string>
#include <vector>
class SSBase
{

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
	int  m_num_comparison;
	bool m_debug;
public:
	/// @Brief Default constructor
	SSBase(): m_num_comparison(0), m_debug(false) {}

	/// @Brief Destructor
	virtual ~SSBase() {}

	/// @brief Search 'pattern' string in 'text' string
	/// @param[in] text string to be searched from
	/// @param[in] pattern string to be searched
	/// @retval index of pattern (if found)
	/// @retval -1 (if not found)
	virtual int Search(const std::string& text, const std::string &pattern) = 0;

	/// @brief Search multiple 'pattern's string in 'text' string
	/// @param[in] text string to be searched from
	/// @param[in] patterns a list of string to be searched
	/// @retval index of pattern (if found)
	/// @retval -1 (if not found)
	virtual int Search(const std::string& text
					   , const std::vector<std::string> &pattern) = 0;

	/// @brief Compare m th. letter of 'pattern' and i th. letter of 'text'
	/// @param[in] text string to be searched from
	/// @param[in] m index of letter to be compared in text
	/// @param[in] pattern string to be searched
	/// @param[in] i index of letter to be compared in pattern	
	/// @retval true Equal
	/// @retval false Not Equal
	bool IsEqual(const std::string& text, int m,
				 const std::string &pattern, int i);
	
	/// @brief Run string search demo
	/// @param[in,out] array to be sorted
	/// @retval 0 Success
	/// @retval Nagative number Error
	int Run(const char* text, const char* pattern);


	/// @brief show brief descrption of the string search alogirhm
	void Help(void) const;

};

#endif /* _SS_BASE_H_ */
