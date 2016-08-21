#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "vertex.h"

/// @brief Graph interface
class Graph
{
public:
	/// @brief Default constructor
	Graph() {}

	/// @brief Destructor
	virtual ~Graph() {}

	/// @brief Add a vertex to graph
	/// @param[in] v vertex to be added
	virtual int AddVertex(const Vertex &v) = 0;

	/// @brief Remove a vetex from graph
	/// @param[in] v vertex to be removed
	virtual int RemoveVertex(const Vertex &v) = 0;

	/// @brief Add an edge 
	/// @param[in] from edge from
	/// @param[in] to   edge to
	virtual int AddEdge(const Vertex& from, const Vertex& to) = 0;

	/// @brief Remove an edge 
	/// @param[in] from edge from
	/// @param[in] to   edge to
	virtual int RemoveEdge(const Vertex& from, const Vertex& to) = 0;

	void Clear(void);
	
	/// @brief Dump whole graph 
	virtual void Dump(void) const = 0;

	/// @brief Create an sample graph
	void CreateSample(void);


};

#endif /* _GRAPH_H_ */
