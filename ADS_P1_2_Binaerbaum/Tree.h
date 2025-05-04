/*************************************************
 * ADS Praktikum 1.2
 * Tree.h
 * Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
 *************************************************/
#pragma once
#include "TreeNode.h"
#include "catch.h"
#include <string>

using namespace std;

class Tree {

private:
    ///////////////////////////////////////
    // Ihr Code hier:
    TreeNode* m_anker;
    int m_currentNodeChronologicalID;
    //
    ////////////////////////////////////

public:
    ///////////////////////////////////////
    // Ihr Code hier:
    Tree();
    ~Tree();
    void addNode(string Name, int Age, double Income, int PostCode);
    bool deleteNode(int NodeOrderID);
    bool searchNode(string Name);
    void printAll();
    void levelOrder();

    //Help function for destruktor
    void helpDestruktor(TreeNode* node);
  
    //Help function for search
    bool helpSearch(TreeNode* ptr, std::string name);

    //Help function for level order
    void helpLO(TreeNode* ptr, int lvl,int ind);

private:
   void printPreOrder(TreeNode* ptr);

   void printInOrder(TreeNode* ptr);

   void printPostOrder(TreeNode* ptr);
    //
    ////////////////////////////////////
    // friend-Funktionen sind für die Tests erforderlich und müssen unangetastet
    // bleiben!
    friend TreeNode* get_anker(Tree& TN);
};
