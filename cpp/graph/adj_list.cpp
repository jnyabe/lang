#include "adj_list.h"
#include "error.h"

bool AdjList::hasVertex(const Vertex &v) const
{
	for(const auto& vinfo: m_vinfoList)
	{
		if(v == vinfo.m_vertex)
		{
			return true;
		}
	}
	
	return false;
}

int AdjList::AddVertex(const Vertex& v)
{
	VertexInfo vinfo;
	vinfo.m_vertex = v;
	
	for(const auto& vinfo: m_vinfoList)
	{
		if(v == vinfo.m_vertex)
		{
			// already added
			return GRAPH_ERROR_VERETX_ALREADY_ADDED;
		}
	}
	
	m_vinfoList.push_back(vinfo);
	
	return GRAPH_OK;
}
	
int AdjList::RemoveVertex(const Vertex &v)
{

	m_vinfoList.erase(remove_if(m_vinfoList.begin(), m_vinfoList.end(),
								[&v](const VertexInfo& vinfo)
								{ return vinfo.m_vertex == v; })
					  , m_vinfoList.end());
	return GRAPH_OK;
}
	
int AdjList::AddEdge(const Vertex& from, const Vertex& to, int cost)
{

	if(!hasVertex(from))
	{
		AddVertex(from);
	}
	
	if(!hasVertex(to))
	{
		AddVertex(to);
	}
	
	for(auto& vinfo: m_vinfoList)
	{
		if(from == vinfo.m_vertex)
		{
			for(const auto& edge: vinfo.m_edges)
			{
				if(edge.m_to == to)
				{
					return -1; // already added
				}
			}
			vinfo.m_edges.push_back({to, cost});
			return GRAPH_OK;
		}
	}

	return GRAPH_ERROR_VERTEX_NOT_FOUND;
}

int AdjList::RemoveEdge(const Vertex& from, const Vertex& to)
{
	return GRAPH_ERROR_NOT_SUPPORTED;
}

void AdjList::Clear(void)
{
	m_vinfoList.clear();
}

void AdjList::Dump(void) const
{
	printf("# of vertex: %d\n", (int)m_vinfoList.size());
	for(const auto& vinfo: m_vinfoList)
	{
		printf("[%d]:", vinfo.m_vertex.m_id);
		for(const auto& edge: vinfo.m_edges)
		{
			printf("->%d(%d),", edge.m_to.m_id, edge.m_cost);
		}
		printf("\n");
	}
}
