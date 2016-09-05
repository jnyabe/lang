#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <list>
#include "vertex.h"

typedef std::list<Vertex> Path;

/// @brief Graph interface
class Graph
{
public:
	/// @brief Default constructor
	Graph() {}

	/// @brief Copy constructor
	Graph(const Graph& g) {}

	/// @brief Destructor
	virtual ~Graph() {}

	/// @brief Add a vertex to graph
	/// @param[in] v vertex to be added
	/// @retval GRAPH_OK Success
	/// @retval GRAPH_ERROR_VERETX_ALREADY_ADDED Already added
	virtual int AddVertex(const Vertex &v) = 0;

	/// @brief Remove a vetex from graph
	/// @param[in] v vertex to be removed
	/// @retval GRAPH_OK Success
	/// @retval GRAPH_ERROR_VERETX_ALREADY_ADDED Already added
	virtual int RemoveVertex(const Vertex &v)  = 0;

	/// @brief Add an edge 
	/// @param[in] from edge from
	/// @param[in] to   edge to
	/// @param[in] cost cost of edge (optional)
	/// @retval GRAPH_OK Success
	virtual int AddEdge(const Vertex& from, const Vertex& to, int cost = 1) = 0;

	/// @brief Remove an edge 
	/// @param[in] from edge from
	/// @param[in] to   edge to
	/// @retval GRAPH_OK Success
	virtual int RemoveEdge(const Vertex& from, const Vertex& to) = 0;
	
	/// @brief Clear graph
	virtual void Clear(void) = 0;
	
	/// @brief Dump whole graph 
	virtual void Dump(void) const = 0;

	/// @brief Create an sample graph
	void CreateSample(void);


};

#endif /* _GRAPH_H_ */
