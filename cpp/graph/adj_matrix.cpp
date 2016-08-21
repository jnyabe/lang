#include "adj_matrix.h"

AdjMatrix::AdjMatrix(int col, int row)
	: m_column(col), m_row(row), m_matrix(col * row)
{
	for(int i=0; i < col * row; i++)
	{
		m_matrix[i] = 0;
	}
}

int AdjMatrix::Set(int col, int row, int value)
{
	if(0 <= col && col < m_column && 0<= row && row < m_row)
	{
		m_matrix[col + row * m_column] = value;
		return 0;
	}
	return -1;
}

int AdjMatrix::Get(int col, int row) const
{
	if(0 <= col && col < m_column && 0<= row && row < m_row)
	{
		return m_matrix[col + row * m_column];
	}
	return -1;
}

void AdjMatrix::Dump() const
{
	for(int i=0; i < m_row; i++)
	{
		for(int j=0; j < m_column; j++)
		{
			printf("%d%c", m_matrix[j + i * m_column],
				   (j == m_column - 1)? '\n':',');
		}
	}
}
