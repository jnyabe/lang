#include "adj_matrix.h"

AdjMatrix::AdjMatrix(int num_vertex)
	: m_num_vertex(num_vertex)
{
	m_matrix.resize(m_num_vertex * m_num_vertex, 0);
}

AdjMatrix::AdjMatrix(const AdjMatrix& mat)
	: Graph(mat)
{
	m_num_vertex = mat.m_num_vertex;
	m_matrix.resize(m_num_vertex * m_num_vertex, 0);
	std::copy(mat.m_matrix.begin(), mat.m_matrix.end(), back_inserter(m_matrix));
}


int AdjMatrix::AddVertex(const Vertex &v)
{
	if(v.m_id > m_num_vertex)
	{
		int num_vertex = v.m_id;

		std::vector<int> tmp(num_vertex * num_vertex, 0);
		for(int i=0; i < m_num_vertex; i++)
		{
			for(int j=0; j < m_num_vertex; j++)
			{
				tmp[i* num_vertex + j] = m_matrix[i * m_num_vertex + j];
			}
		}
		m_matrix.resize(num_vertex * num_vertex);
		for(int i=0; i < num_vertex * num_vertex; i++)
			m_matrix[i] = tmp[i];
		m_num_vertex = num_vertex;
	}
	return 0;
}

int AdjMatrix::RemoveVertex(const Vertex &v)
{
	for(int i=0; i < m_num_vertex; i++)
	{
		// clean edge to/from the denoted vertex
		m_matrix[m_num_vertex * i + v.m_id - 1] = 0;
		m_matrix[(v.m_id - 1) * m_num_vertex + i] = 0;	
	}
	return 0;
}

int AdjMatrix::AddEdge(const Vertex& from, const Vertex& to, int cost)
{
	int ret = 0;
	
	if(m_num_vertex < from.m_id)
	{
		ret = AddVertex(from);
	}
	if(m_num_vertex < to.m_id)
	{
		ret = AddVertex(to);
	}

	m_matrix[(from.m_id-1) * m_num_vertex + (to.m_id - 1)] = cost;
	m_matrix[(to.m_id-1) * m_num_vertex + (from.m_id - 1)] = cost;
	
	return ret;
}

int AdjMatrix::RemoveEdge(const Vertex& from, const Vertex& to)
{
	m_matrix[(from.m_id-1) * m_num_vertex + (to.m_id - 1)] = 0;
	m_matrix[(to.m_id-1) * m_num_vertex + (from.m_id - 1)] = 0;
	return 0;
}


void AdjMatrix::Clear(void)
{
	m_num_vertex = 0;
	m_matrix.clear();
}

void AdjMatrix::Dump() const
{
	printf("# of vertex: %d\n", m_num_vertex);
	for(int i=0; i < m_num_vertex; i++)
	{
		for(int j=0; j < m_num_vertex; j++)
		{
			printf("%d%c", m_matrix[j + i * m_num_vertex],
				   (j == m_num_vertex - 1)? '\n':',');
		}
	}
}
