/*************************************************
* ADS Praktikum 1.1
* RingNode.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "RingNode.h"

////////////////////////////////////
// Ihr Code hier:
/* - - - - - Konstruktor - - - - - */
RingNode::RingNode() : m_next{nullptr} {}

RingNode::RingNode(int oldAge, std::string description, std::string symbolicData) :
 m_oldAge{oldAge}, m_description{description}, m_symbolicData{symbolicData}, m_next{nullptr} {}

/* - - - - - Setters - - - - - */
void RingNode::setOldAge(int oldAge) {m_oldAge = oldAge;}

void RingNode::setDescription(std::string description) {m_description = description;}

void RingNode::setSymbolicData(std::string symbolicData){m_symbolicData = symbolicData;}

void RingNode::setNext(RingNode* next) {m_next = next;}

/* - - - - - Getters - - - - - */
int RingNode::getOldAge() {return m_oldAge;}

std::string RingNode::getDescription() {return m_description;}

std::string RingNode::getSymbolicData() {return m_symbolicData;}

RingNode* RingNode::getNext() {return m_next;}
// 
////////////////////////////////////