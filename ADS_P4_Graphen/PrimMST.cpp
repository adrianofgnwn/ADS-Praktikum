#include "PrimMST.h"

/**
 * Erstellt einen MST zum Graph G mit dem Prim Algorithmus
 *
 * \param[in]  G		Kantengewichteter-Graph
 * \param[in]  s		Startknoten
 */
PrimMST::PrimMST(EdgeWeightedGraph G, int s)
{
	marked.resize(G.getV(), false);
   	// setzt voraus, dass G zusammenhaengend ist
   	visit(G,s);

	while (!pq.empty()) {
		Edge e = pq.top(); // Hole Kante mit geringstem Gewicht aus PQ
		pq.pop();          // entferne diese Kante aus PQ
		int v = e.either(); // Knoten 1 der Kante
		int w = e.other(v); // Knoten 2 der Kante

		// Überspringen, falls beide Knoten im Baum markiert sind
		if (marked[v] && marked[w]) continue; // Zykel-Detektion

		mst.push_back(e);            // Füge Kante e zum MSP hinzu
		if (!marked[v]) visit(G, v); // Knoten v oder w zum MSP
		if (!marked[w]) visit(G, w); // hinzufügen
	}	
}

/**
 * Markiert Knoten v im Graph G als markiert und fuegt alle Nachbarn zur pq hinzu
 *
 * \param[in]  G		Kantengewichteter-Graph
 * \param[in]  v		Knoten im Graph G
 */
void PrimMST::visit(EdgeWeightedGraph G, int v)
{
	// Markiere Knoten v als besucht
   	marked[v] = true;
   	std::vector<Edge> edges = G[v]; // liefert alle Kanten ausgehend vom Knoten v
   	// Lege alle Kanten von v zu unmarkierten
   	// (noch nicht besuchten) Knoten in die PQ ab
   	for(int i = 0; i < edges.size(); i++){
    	if (!marked[edges[i].other(v)]) pq.push(edges[i]);
   	}

}

/**
 * Gibt alle Kanten vom MST zurueck
 *
 * \return Vektor mit Kanten des MST
 */
std::vector<Edge> PrimMST::edges() const
{
	return this->mst;
}

/**
 * Gibt die Summe aller Gewichte im MST zurueck
 *
 * \return Summe der Gewichte im MST
 */
double PrimMST::weight() const
{
	std::vector<Edge> edgeweight = edges();
	double res = 0.0;
	for (int i = 0; i < edgeweight.size(); i++) {
		res += edgeweight[i].weight();
	}
	return res;
}

void PrimMST::print() const {
	bool a = true;
	for (int i = 0; i < mst.size(); i++) {
		a = true;
		std::cout << std::endl;
		for (int k = 0; k < mst.size(); k++) {
			if (mst[k].either() == i) {
				if (a) {
					std::cout << i << " -> " << mst[k].other(i) << " [" << mst[k].weight() << "]";
					a = false;
				}
				else
					std::cout << " -> " << mst[k].other(i) << " [" << mst[k].weight() << "]";

			}
		}
	}
}
