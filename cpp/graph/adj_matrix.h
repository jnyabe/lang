#ifndef _ADJ_MATRIX_H_
#define _ADJ_MATRIX_H_

#include "graph.h"
#include <vector>

/// @brief Adjacency Matrix
class AdjMatrix : public Graph
{
private:
	int m_num_vertex;
	std::vector<int> m_matrix;
	
public:
	/// @brief Default constructor
	AdjMatrix(): m_num_vertex(0){}

	/// @brief Constructor with size
	AdjMatrix(int num_vertex);

	/// @brief Destructor
	virtual ~AdjMatrix() {}

	/// @brief Add a vertex to graph
	/// @param[in] v vertex to be added
	virtual int AddVertex(const Vertex &v);

	/// @brief Remove a vetex from graph
	/// @param[in] v vertex to be removed
	virtual int RemoveVertex(const Vertex &v);

	/// @brief Add an edge 
	/// @param[in] from edge from
	/// @param[in] to   edge to
	/// @param[in] cost
	virtual int AddEdge(const Vertex& from, const Vertex& to, int cost = 1);

	/// @brief Remove an edge 
	/// @param[in] from edge from
	/// @param[in] to   edge to
	virtual int RemoveEdge(const Vertex& from, const Vertex& to);

	virtual void Clear(void);
	
	virtual void Dump(void) const;
};

#endif /* _ADJ_MATRIX_H_ */
