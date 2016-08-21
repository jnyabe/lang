#ifndef _VERTEX_H_
#define _VERTEX_H_

/// @brief Vertex class
class Vertex
{
public:
	int m_id;

	/// @brief Defalt costructor
	Vertex(): m_id(0) {}

	/// @brief Constructor with ID
	/// @pram[in] id ID for the vertex
	Vertex(int id): m_id(id) {}

	/// @brief Copy Constructor
	/// @pram[in] v Vertex object to be copied
	Vertex(const Vertex& v): m_id(v.m_id) {}

	/// @brief Destructor
	virtual ~Vertex() {}

	/// @brief Assignment operator
	const Vertex& operator=(const Vertex& v) { m_id = v.m_id; return *this; }

	/// @brief Equality operator
	bool operator==(const Vertex& v) const { return this->m_id == v.m_id; }

	/// @brief Not-Equality operator
	bool operator!=(const Vertex& v) const { return !(*this==v); }
};
	
#endif /* _VERTEX_H_ */
