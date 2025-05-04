/*************************************************
 * ADS Praktikum 1.2
 * TreeNode.cpp
 * Erweiterung um Hilfsfunktionen gestattet.
 *************************************************/
#include "TreeNode.h"
#include <iostream>
#include <string>

////////////////////////////////////
// Ihr Code hier:
/* - - - - - Konstruktor - - - - - */
TreeNode::TreeNode(int NodeOrderID, int NodeChronologicalID, std::string Name, int Age, double Income, int PostCode) :
m_NodeOrderID{NodeOrderID}, m_NodeChronologicalID{NodeChronologicalID}, m_Name{Name},
m_Age{Age}, m_Income{Income}, m_PostCode{PostCode} {}

/* - - - - - Setters - - - - - */
void TreeNode::setNodeOrderID(int node_order) {this->m_NodeOrderID = node_order;}

void TreeNode::setNodeChronologicalID(int node_chronological) {this->m_NodeChronologicalID = node_chronological;}

void TreeNode::setName(std::string name) {this->m_Name = name;}

void TreeNode::setAge(int age) {this->m_Age = age;}

void TreeNode::setIncome(double income) {this->m_Income = income;}

void TreeNode::setPostCode(int postcode) {this->m_PostCode = postcode;}

void TreeNode::setRight(TreeNode* right) {this->m_right = right;}

void TreeNode::setLeft(TreeNode* left) {this->m_left = left;}

/* - - - - - Getters - - - - - */
int TreeNode::getNodeOrderID() {return this->m_NodeOrderID;}

int TreeNode::getNodeChronologicalID() {return this->m_NodeChronologicalID;}

std::string TreeNode::getName() {return this->m_Name;}

int TreeNode::getAge() {return this->m_Age;}

double TreeNode::getIncome() {return this->m_Income;}

int TreeNode::getPostCode() {return this->m_PostCode;}

TreeNode* TreeNode::getRight() {return this->m_right;}

TreeNode* TreeNode::getLeft() {return this->m_left;}

/* - - - - - Methoden - - - - - */
void TreeNode::print() {
    cout << "NodeID: " << getNodeChronologicalID()
         << ", Name: " << getName()
         << ", Alter: " << getAge()
         << ", Einkommen: " << getIncome()
         << ", PLZ: " << getPostCode()
         << ", PosID: " << getNodeOrderID() << endl;
}
//
////////////////////////////////////
