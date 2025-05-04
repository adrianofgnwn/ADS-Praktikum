/*************************************************
* ADS Praktikum 1.1
* Ring.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring .cpp
#include "Ring.h"
#include <iostream>

// Ihr Code hier:
Ring::Ring() : m_countNodes{0}, m_anker{nullptr} {}

void Ring::addNewNode(std::string description, std::string symbolischeData) {
    //Prepare new node
    RingNode* newNode = new RingNode(0, description, symbolischeData);


    //Case: empty ring
    if (m_countNodes == 0) {
        m_anker = newNode;
        m_anker->setNext(newNode);
        m_countNodes++;
  
    //Case: ring node is 6 (max)
    } else if (m_countNodes == 6) {
        //delete oldest Node
        RingNode* deleteNode = m_anker->getNext();
        newNode->setNext(m_anker->getNext()->getNext());
        m_anker->setNext(newNode);
        m_anker = newNode;
        delete deleteNode;

        RingNode* tmp = newNode->getNext();

        for (int i = 1; i < m_countNodes; i++) {
            tmp->setOldAge(tmp->getOldAge() + 1);
            tmp = tmp->getNext();
        }
      
    } else {
        newNode->setNext(m_anker->getNext());
        m_anker->setNext(newNode);
        m_anker = newNode;
        m_countNodes++;

        RingNode* tmp = newNode->getNext();

        for (int i = 1; i < m_countNodes; i++) {
            tmp->setOldAge(tmp->getOldAge() + 1);
            tmp = tmp->getNext();
        }
    }
}

bool Ring::search(std::string symbolischeData) {
    if (m_anker != nullptr) {
        RingNode* tmp = m_anker->getNext();

        for (int i = 0; i < m_countNodes; i++) {
            if (tmp->getSymbolicData() == symbolischeData) {
                std::cout << "Gefunden in Backup: Alter " << tmp->getOldAge()
                          << ", Beschreibung: " << tmp->getDescription()
                          << ", Daten: " << tmp->getSymbolicData() << std::endl;
                return true;
            }
          
            tmp = tmp->getNext();
        }
      
    }
  
    std::cout << "Datensatz konnte nicht gefunden werden." << std::endl;
    return false;
}

void Ring::print() {
    //Case: empty ring
    if (m_anker == nullptr) {
        std::cout << "Es existiert derzeit kein Backup." << std::endl;
        return;
    }
  
    RingNode* tmp = m_anker;

    std::cout << "Alter: " << tmp->getOldAge()
              << ", Beschreibung: " << tmp->getDescription()
              << ", Daten: " << tmp->getSymbolicData() << std::endl;
    std::cout << "-------------------------" << std::endl;

    RingNode* tmp2 = m_anker;
    int count = 0;

    while (count < m_countNodes - 1) {
        tmp2 = tmp2->getNext();


        if (tmp2->getNext() == tmp) {
            std::cout << "Alter: " << tmp2->getOldAge()
                      << ", Beschreibung: " << tmp2->getDescription()
                      << ", Daten: " << tmp2->getSymbolicData() << std::endl;
            std::cout << "-------------------------" << std::endl;


            tmp = tmp2;
            count++;


        }
      
    }
  
}
//
////////////////////////////////////