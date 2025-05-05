#include <assert.h>
#include "DijkstraSP.h"

/**
 * F�ge eine Kante mit minimalen Kosten hinzu, die von einem
 * Baumknoten zu einem Nicht-Baumknoten verl�uft und deren
 * Ziel w dem Startknoten s am n�chsten ist.
 *
 * \param[in]  G		Kantengewichteter-Digraph
 * \param[in]  v		Zielknoten
 */
void DijkstraSP::relax(EdgeWeightedDigraph G, int v)
{
	std::vector<DirectedEdge> edges = G[v];
  	for (DirectedEdge e : edges)
  	{
    	int w = e.to();
    	if (distToVect[w] > distToVect[v] + e.weight())
    	{
      		distToVect[w] = distToVect[v] + e.weight();
      		edgeTo[w] = e;
      		if (pq.contains(w))
      		{   pq.change(w, distToVect[w]); }
      		else
      		{ pq.push(w, distToVect[w]); }

		} 
	}
}

/**
 * Fuert den Dijkstra Algorithmus von s, im Graph G aus.
 *
 * \param[in]  G		Kantengewichteter-Digraph
 * \param[in]  s		Startknoten
 */
DijkstraSP::DijkstraSP(EdgeWeightedDigraph G, int s)
{
	distToVect.resize(G.getV());
  	for (int v = 0; v < G.getV(); v++) {
    	distToVect[v] = DBL_MAX;
  	}
  	distToVect[s] = 0.0;
  	pq.push(s, 0.0);
  	while (!pq.empty())
  	{
    	int min_node = pq.top().value;
    	pq.pop();
    	// Füge immer eine Kante mit minimalen Pfadkosten zu s hinzu
    	relax(G, min_node);
	}
}

/**
 * Gibt die Distanz von s zum Knoten v zurueck
 *
 * \param[in]  v		Zielknoten
 * \return Summe der Gewichte auf dem Pfad zu v
 */
double DijkstraSP::distTo(int v) const
{
	return this->distToVect[v];
}

/**
 * Gibt zurueck ob es einen Pfad zu v von s aus gibt
 *
 * \param[in]  v		Zielknoten
 * \return true, wenn es einen Pfad von s nach v gibt, sonst false
 */
bool DijkstraSP::hasPathTo(int v) const
{
	if (distTo(v) < DBL_MAX)// nicht unendlich
		return true;
	else
		return false;
}

/**
 * Gibt den Pfad von s nach v als Vektor zurueck
 *
 * \param[in]  v		Zielknoten
 * \return Vektor mit allen Kanten des Pfades von s nach v
 */
std::vector<DirectedEdge> DijkstraSP::pathTo(int v) 
{
	// Create an empty vector to store the path
	std::vector<DirectedEdge> path;

	// Set the current vertex to v
	int ptr = v;

	// While the distance to the current vertex is greater than 0
	while (distToVect[ptr] > 0.0)
	{
		// Add the edge leading to the current vertex to the path
		path.push_back(edgeTo[ptr]);

		// Set the current vertex to the vertex the edge is coming from
		ptr = edgeTo[ptr].from();
	}

	// Reverse the path to get the correct order
	std::reverse(path.begin(), path.end());

	// Return the path
	return path;
}
