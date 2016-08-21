#ifndef _ADJ_LIST_H_
#define _ADJ_LIST_H_

#include <list>
#include "graph.h"


class AdjList: public Graph
{
private:
	class VertexInfo
	{
	public:
		Vertex            m_vertex;
		std::list<Vertex> m_edges;
	};
	
	std::list<VertexInfo> m_vinfoList;
public:
	AdjList() {};
	virtual ~AdjList() {};

	/// @brief Add a vertex to graph
	/// @param[in] v vertex to be added
	virtual int AddVertex(const Vertex &v);

	/// @brief Remove a vetex from graph
	/// @param[in] v vertex to be removed
	virtual int RemoveVertex(const Vertex &v);

	/// @brief Add an edge 
	/// @param[in] from edge from
	/// @param[in] to   edge to
	virtual int AddEdge(const Vertex& from, const Vertex& to);

	/// @brief Remove an edge 
	/// @param[in] from edge from
	/// @param[in] to   edge to
	virtual int RemoveEdge(const Vertex& from, const Vertex& to);

	virtual void Dump(void) const;
};

#endif /* _ADJ_LIST_H_ */
