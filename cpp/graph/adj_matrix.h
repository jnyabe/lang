#ifndef _ADJ_MATRIX_H_
#define _ADJ_MATRIX_H_

#include <vector>

/// @brief Adjacency Matrix
class AdjMatrix
{
private:
	int m_column;
	int m_row;
	std::vector<int> m_matrix;
	
public:
	/// @brief Default constructor
	AdjMatrix(): m_column(0), m_row(0) {}

	/// @brief Constructor with size
	AdjMatrix(int col, int row);

	/// @brief Destructor
	virtual ~AdjMatrix() {}


	int Set(int col, int row, int value);
	int Get(int col, int row) const;
	
	void Dump(void) const;
};

#endif /* _ADJ_MATRIX_H_ */
