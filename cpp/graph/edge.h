#ifndef _EDGE_H_
#define _EDGE_H_

#include "vertex.h"

/// @brief Edge class
class Edge
{
public:
	const Vertex* m_from;
	const Vertex* m_to;
	
	/// @brief Defalt costructor
	Edge(): m_from(nullptr), m_to(nullptr){}
	
	/// @brief Constructor with from/to vertex
	Edge(const Vertex* from, const Vertex* to)
		: m_from(from), m_to(to) {}

	Edge(const Edge& edge):
		m_from(edge.m_from), m_to(edge.m_to) {}
	
	/// @brief Destructor
	virtual ~Edge() {}

	/// @brief Assignment operator
	const Edge& operator=(const Edge& edge) {
		m_from = edge.m_from;
		m_to = edge.m_to;
		return *this; }

	/// @brief Equality operator
	bool operator==(const Edge& edge) const {
		return m_from == edge.m_from && m_to == edge.m_to;
	}
	
	/// @brief Not-Equality operator
	bool operator!=(const Edge& edge) const { return !(*this==edge); }
};
	
#endif /* _EDGE_H_ */
