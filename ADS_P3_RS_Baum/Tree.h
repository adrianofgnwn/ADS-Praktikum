/*************************************************
* ADS Praktikum 3
* Tree.h
* Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
*************************************************/
#pragma once
#include <string>
#include "TreeNode.h"
#include "catch.h"


class Tree {
	
private: 
	TreeNode * m_anker;
	int m_CurrentNodeChronologicalID;
	void balance(TreeNode*);
	bool split4Node(TreeNode*);
	bool rotateTreeRight(TreeNode*,TreeNode*);
	bool rotateTreeLeft(TreeNode*,TreeNode*);
	void preOrder(TreeNode*);
	
			
public:
	Tree();
	~Tree();
	bool addNode(std::string Name, int Age, double Income, int PostCode);	
	bool searchNode(std::string);

	void printAll();
	int proofRBCriterion(TreeNode*);
	void printLevelOrder();
	void printLevelOrder(int);
	void printLvlOrder();
	void lvlOrder(TreeNode*);


	
	// friend-Funktionen sind f�r die Tests erforderlich und m�ssen unangetastet bleiben! 
	friend TreeNode * get_anker(Tree& TN);
};
