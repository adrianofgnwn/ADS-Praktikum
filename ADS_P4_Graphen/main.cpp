#define CATCH_CONFIG_RUNNER
#include "catch.h"
#include <iostream>
#include "EdgeWeightedGraph.h"
#include "PrimMST.h"
#include "Graphsearch.h"
#include "KruskalMST.h"
#include "DijkstraSP.h"

int main() {
	// Starte Unit-Tests
	Catch::Session().run();

	//------------------------------------------------------------------------
	// 1. Ausgabe eines Graphen als Adjazenzliste implementieren
	//------------------------------------------------------------------------
	


	//------------------------------------------------------------------------
	// 2. Suche in Graphen
	//------------------------------------------------------------------------
	// Verwenden Sie hierf�r die Vorlagen in Graphsearch.h
	//
	// Beispielaufruf der Tiefensuche: 
	// std::vector<bool> marked;
	// std::vector<int>  edgeTo;
	// bool connected = Graphsearch::DFS(G1, start, marked, edgeTo);



	//------------------------------------------------------------------------
	// 3. Minimaler Spannbaum mit Prim und Kruskal
	//------------------------------------------------------------------------
	// Vorlage f�r Prim ist die Klasse PrimMST (PrimMST.h + PrimMST.cpp)
	// Vorlage f�r Kruskal ist die Klasse KruskalMST (KruskalMST.h + KruskalMST.cpp)
	//
	// Beispielaufruf von Prim:
	// PrimMST prim(G, 0);



	//------------------------------------------------------------------------
	// 4. Kuerzeste Wege mit Dijkstra
	//------------------------------------------------------------------------
	// Beispielaufruf von Dijkstra
	//
	// EdgeWeightedDigraph G1_directed("graph1.txt");
	// Dijkstra dijkstra(G1_directed, start);
	// path = dijkstra.pathTo(target);



	//------------------------------------------------------------------------
	// 5. Men� f�r Benutzereingaben
	//------------------------------------------------------------------------
	// Alle Funktionalit�ten aus der Aufgabenstellung muessen umgesetzt werden
	std::cout << "Praktikum 5: Graphenalgorihtmen: " << std::endl << std::endl;
	int eingabe, g, s, z;
	EdgeWeightedGraph G(0);
	EdgeWeightedDigraph dG(0);
	while (true) {
		std::cout << "Menu :" << std::endl
			<< "1) Graph einlesen" << std::endl
			<< "2) Tiefensuche" << std::endl
			<< "3) Breitensuche" << std::endl
			<< "4) MST nach Prim (Eingabe: Startknoten)" << std::endl
			<< "5) MST nach Kruskal" << std::endl
			<< "6) Kuerzeste Wege nach Dijkstra (Eingabe: Startknoten)" << std::endl
			<< "7) Ausgabe der Adjazenzliste" << std::endl
			<< "8) Kante loeschen" << std::endl
			<< "9) Kante einfuegen" << std::endl
			<< "10) Programm beenden" << std::endl
			<< "weiter mit beliebiger Eingabe..." << std::endl
			<< "?> ";
		std::cin >> eingabe;
		if (eingabe == 1) {
			std::cout << "Welche Graph-Datei m�chten Sie einlesen ?" << std::endl
				<< "1) graph1.txt" << std::endl
				<< "2) graph2.txt" << std::endl
				<< "3) graph3.txt" << std::endl
				<< "?>";
			std::cin.ignore();
			std::cin >> g;
			if (g == 1) {
				G = EdgeWeightedGraph("graph1.txt");
				dG = EdgeWeightedDigraph("graph1.txt");
			}
			if (g == 2) {
				G = EdgeWeightedGraph("graph2.txt");
				dG = EdgeWeightedDigraph("graph2.txt");
			}
			if (g == 3) {
				G = EdgeWeightedGraph("graph3.txt");
				dG = EdgeWeightedDigraph("graph3.txt");
			}
			std::cout << "Graph eingelesen.";
			std::cout << std::endl << std::endl;

		}
		else if (eingabe == 2) {
			int v = 5;
			std::vector<bool>marked;
			std::vector<int>edgeTo;
			bool result;
			std::cout << "Tiefensuche (Depth-First-Search (DFS)) - Startknoten: " << v << std::endl
				<< "Besuchreihenfolge: " << std::endl;
			result = Graphsearch::DFS(G, v, marked, edgeTo);
			std::cout << std::endl << std::endl << "EdgeTo_Array: " << std::endl;
			for (int i = 0; i < edgeTo.size(); i++) {
				std::cout << i << " -> " << edgeTo[i];
				if (i == v)
					std::cout << " (Startknoten)";
				std::cout << std::endl;
			}
			std::cout << std::endl;
			std::cout << std::endl << std::endl << "Marked_Array: " << std::endl;
			for (int i = 0; i < marked.size(); i++) {
				std::cout << i << " -> " << marked[i];
				if (i == v)
					std::cout << " (Startknoten)";
				std::cout << std::endl;
			}
			if (result)
				std::cout << "Graph ist zusammenhaengend.";
			else
				std::cout << "Graph ist nicht zusammenhaengend.";
			std::cout << std::endl << std::endl;
		}
		else if (eingabe == 3) {
			int v = 5;
			std::vector<bool>marked;
			std::vector<int>edgeTo;
			bool result;
			std::cout << "Tiefensuche (Depth-First-Search (DFS)) - Startknoten: " << v << std::endl
				<< "Besuchreihenfolge: " << std::endl;
			result = Graphsearch::BFS(G, v, marked, edgeTo);
			std::cout << std::endl << std::endl << "EdgeTo_Array: " << std::endl;
			for (int i = 0; i < edgeTo.size(); i++) {
				std::cout << i << " -> " << edgeTo[i];
				if (i == v)
					std::cout << " (Startknoten)";
				std::cout << std::endl;
			}
			std::cout << std::endl;
			std::cout << std::endl << std::endl << "Marked_Array: " << std::endl;
			for (int i = 0; i < marked.size(); i++) {
				std::cout << i << " -> " << marked[i];
				if (i == v)
					std::cout << " (Startknoten)";
				std::cout << std::endl;
			}
			if (result)
				std::cout << "Graph ist zusammenhaengend.";
			else
				std::cout << "Graph ist nicht zusammenhaengend.";
			std::cout << std::endl << std::endl;
		}
		else if (eingabe == 4) {
			std::cin.ignore();
			std::cout << "Bitte Startknoten eingeben: " << std::endl
				<< "?> ";
			std::cin >> s;
			PrimMST prim(G, s);
			std::cout << std::endl << "Minimaler Spannbaum (MST) nach Prim: " << std::endl
				<< "Gewicht: " << prim.weight() << std::endl
				<< "Adjazentliste: " << std::endl;
			prim.print();
			std::cout << std::endl << std::endl;
		}
		else if (eingabe == 5) {
			KruskalMST kruskal(G);
			std::cout << std::endl << "Minimaler Spannbaum (MST) nach Kruskal: " << std::endl
				<< "Gewicht: " << kruskal.weight() << std::endl
				<< "Adjazentliste: " << std::endl;
			kruskal.print();
			std::cout << std::endl << std::endl;
		}
		else if (eingabe == 6) {
			std::cin.ignore();
			std::cout << "Bitte Startknoten eingeben: " << std::endl
				<< "?> ";
			std::cin >> s;
			std::cout << "Bitte Zielknoten eingeben: " << std::endl
				<< "?> ";
			std::cin >> z;
			dG.print();
			DijkstraSP dijkstra(dG, s);
			std::cout << std::endl << "Kuerzester Weg (Dijkstra) :" << std::endl
				<< "Start  : " << s << std::endl
				<< "Ziel   : " << z << std::endl
				<< "Pfad :";
			if (dijkstra.hasPathTo(z)) {
				std::vector<DirectedEdge> pfad = dijkstra.pathTo(z);
				std::cout << pfad[0].from();
				for (int i = 0; i < pfad.size(); i++) {
					std::cout << "[" << pfad[i].weight() << "] -> " << pfad[i].to();
				}
				std::cout << std::endl << "Kosten: " << dijkstra.distTo(z);
			}
			else
				std::cout << "Es gibt keinen Pfad von Start nach Ziel.";
			std::cout << std::endl << std::endl;
		}
		else if (eingabe == 7) {
			G.print();
			std::cout << std::endl << std::endl;
		}
		else if (eingabe == 8) 
		{
			// Kante loeschen
			std::cout << "Kante loeschen:\n";
			std::cout << "Startknoten: ";
			int from;
			std::cin >> from;
			std::cout << "Endknoten: ";
			int to;
			std::cin >> to;
			std::cout << "Gewicht: ";
			double weight;
			std::cin >> weight;

			Edge e(from, to, weight);
			if (G.del_Edge(e)) {
				std::cout << "Kante wurde geloescht.\n";
			}
			else {
				std::cout << "Kante wurde nicht gefunden.\n";
			}
		}
		else if (eingabe == 9) {
			// Kante hinzufuegen
			int from, to;
			double weight;
			std::cout << "Kante hinzufuegen\n";
			std::cout << "Startknoten: ";
			std::cin >> from;
			std::cout << "Endknoten: ";
			std::cin >> to;
			std::cout << "Gewicht: ";
			std::cin >> weight;

			Edge edge(from, to, weight);
			G.add(edge);

			std::cout << "Kante erfolgreich hinzugefuegt.\n";
		}
		else if (eingabe == 10) {
			break;
			std::cout << std::endl;
		}
	}

	system("PAUSE");
	return 0;
}