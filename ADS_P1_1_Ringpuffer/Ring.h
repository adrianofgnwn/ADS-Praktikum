/*************************************************
* ADS Praktikum 1.1
* Ring.h
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring .h
#pragma once
#include<string>
#include "catch.h"
#include"RingNode.h"

class Ring {
	
private:
	// Ihr Code hier:	
	int m_countNodes;
	RingNode* m_anker;
	//
	////////////////////////////////////
public:
	// Ihr Code hier:
	Ring();
   	void addNewNode(std::string description, std::string symbolicData);
   	bool search(std::string symbolicData);
   	void print();
	//
	////////////////////////////////////
	// friend Funktionen müssen unangetastet bleiben! 
	friend RingNode * get_anker(Ring& r);
	friend int get_countNodes(Ring& r);
};
