#ifndef _ADJ_LIST_H_
#define _ADJ_LIST_H_

#include <list>
#include "graph.h"


class AdjList: public Graph
{
private:
	struct Edge
	{
		Vertex m_to;
		int    m_cost;
	};
	
	class VertexInfo
	{
	public:
		Vertex            m_vertex;
		std::list<Edge>   m_edges;
	};
	
	std::list<VertexInfo> m_vinfoList;

	bool hasVertex(const Vertex &v) const;
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
	/// @param[in] cost 
	virtual int AddEdge(const Vertex& from, const Vertex& to, int cost = 1);

	/// @brief Remove an edge 
	/// @param[in] from edge from
	/// @param[in] to   edge to
	virtual int RemoveEdge(const Vertex& from, const Vertex& to);

	virtual void Clear(void);
	
	virtual void Dump(void) const;
};

#endif /* _ADJ_LIST_H_ */
