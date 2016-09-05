#ifndef _VERTEX_H_
#define _VERTEX_H_

/// @brief Vertex class
class Vertex
{
	
public:
	const int UNKNOWN_COST = -1;
	int  m_id;

	// for Dijkstra's Algorithm
	bool m_done;      // 確定ノードかどうか? 
	int  m_min_cost;  // このノードへの最小コスト 
	
	/// @brief Defalt costructor
	Vertex(): m_id(0), m_done(false), m_min_cost(UNKNOWN_COST) {}

	/// @brief Constructor with ID
	/// @pram[in] id ID for the vertex
	Vertex(int id): m_id(id), m_done(false), m_min_cost(UNKNOWN_COST) {}

	/// @brief Copy Constructor
	/// @pram[in] v Vertex object to be copied
	Vertex(const Vertex& v):
		m_id(v.m_id), m_done(v.m_done), m_min_cost(v.m_min_cost) {}

	/// @brief Destructor
	virtual ~Vertex() {}

	/// @brief Assignment operator
	const Vertex& operator=(const Vertex& v) {
		m_id = v.m_id;
		m_done = v.m_done;
		m_min_cost = v.m_min_cost;
		return *this; }

	/// @brief Equality operator
	bool operator==(const Vertex& v) const { return this->m_id == v.m_id; }

	/// @brief Not-Equality operator
	bool operator!=(const Vertex& v) const { return !(*this==v); }
};
	
#endif /* _VERTEX_H_ */
