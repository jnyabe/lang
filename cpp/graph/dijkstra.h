#ifndef _DIJKSTRAT_H_
#define _DIJKSTRAT_H_

#include "graph.h"

/// @brief Dijkstra's Algorithm
class Dijkstar
{
public:
	/// @brief Default constructor
	Dijkstar();

	/// @brief Destructor
	virtual ~Dijkstar();

	/// @brief
	/// 
	int GetShortestPath(Graph &g, const Vertex &s, const Vertex &goal,
						Path& path);
			   
};

#endif /* _DIJKSTRAT_H_ */
