/*************************************************
 * ADS Praktikum 1.2
 * Tree.cpp
 * Erweiterung um Hilfsfunktionen gestattet.
 *************************************************/
#include "Tree.h"
#include "TreeNode.h"
#include <iomanip>
#include <iostream>

using namespace std;

////////////////////////////////////
// Ihr Code hier:
Tree::Tree() : m_anker{nullptr}, m_currentNodeChronologicalID{0} {}

Tree::~Tree() {
   helpDestruktor(m_anker);
}

void Tree::helpDestruktor(TreeNode* node) {
    if (node == nullptr) {
        return;
    }

    helpDestruktor(node->getLeft());
    helpDestruktor(node->getRight());

    delete node;
}

void Tree::addNode(string Name, int Age, double Income, int PostCode) {
    //Formula for NodeOrderID
    int NodeOrderID = Age + Income + PostCode;

    //Prepare new node
    TreeNode* newNode = new TreeNode(NodeOrderID, m_currentNodeChronologicalID, Name, Age, Income, PostCode);

    TreeNode* eltern = m_anker;
    TreeNode* kind;

    //Case: empty tree
    if (m_anker == nullptr) {
        m_anker = newNode;
  
    } else {
        if (m_anker->getNodeOrderID() > newNode->getNodeOrderID()) {
            kind = eltern->getLeft();
      
        } else {
            kind = eltern->getRight();
        }
      
        while (kind != nullptr) {
            eltern = kind;

            if (kind->getNodeOrderID() > newNode->getNodeOrderID()) {
                kind = kind->getLeft();
                         
            } else {
                kind = kind->getRight();
            } 
        }

        if (eltern->getNodeOrderID() > newNode->getNodeOrderID()) {
            eltern->setLeft(newNode);
      
        } else {
            eltern->setRight(newNode);
        }
    }

    m_currentNodeChronologicalID++;
}

bool Tree::deleteNode(int NodeOrderID) {
    TreeNode* gesucht = m_anker;
    TreeNode* eltern = nullptr;

    while (gesucht != nullptr && gesucht->getNodeOrderID() != NodeOrderID) {
        eltern = gesucht;

        if (gesucht->getNodeOrderID() > NodeOrderID) {
            gesucht = gesucht->getLeft();
      
        } else {
            gesucht = gesucht->getRight();
        }
    }
  
    //Case: not found
    if (gesucht == nullptr) {
        return false;
  
    //Case: no child 
    } else if (gesucht->getLeft() == nullptr && gesucht->getRight() == nullptr) {
        if (eltern == nullptr) {
            m_anker = nullptr;
        
        } else {
            if (eltern->getLeft() == gesucht) {
                eltern->setLeft(nullptr);
          
            } else {
                eltern->setRight(nullptr);
            }
        }
       
        delete gesucht;
        m_currentNodeChronologicalID--;
        
        return true;
  
    //Case: 1 child
    } else if (!(gesucht->getLeft() != nullptr && gesucht->getRight() != nullptr)) {
        TreeNode* kind;

        if (gesucht->getLeft() != nullptr) {
            kind = gesucht->getLeft();
      
        } else {
            kind = gesucht->getRight();
        }
      
        if (eltern == nullptr) {
            m_anker = kind;
      
        } else {
            if (eltern->getLeft() == gesucht) {
                eltern->setLeft(kind);
          
            } else {
                eltern->setRight(kind);
            }
        }
        
        delete gesucht;
        m_currentNodeChronologicalID--;
       
        return true;
  
    //Case: 2 child
    } else {
        TreeNode *eltern_min, *min;
        eltern_min = gesucht;
        min = gesucht->getRight();

        while (min->getLeft() != nullptr) {
            eltern_min = min;
            min = min->getLeft();
        }

        min->setLeft(gesucht->getLeft());

        if (eltern_min != gesucht) {
            eltern_min->setLeft(min->getRight());
            min->setRight(gesucht->getRight());
        }


        if (eltern == nullptr) {
            m_anker = min;
      
        } else {
            if (eltern->getLeft() == gesucht) {
                eltern->setLeft(min);
          
            } else {
                eltern->setRight(min);
            }
        }
      
        delete gesucht;
        m_currentNodeChronologicalID--;
       
        return true;
    }   
}

bool Tree::searchNode(string Name) {
    cout << "+Fundstellen: \n";
    
    if (helpSearch(m_anker, Name)) {
       return true;
  
    } else {
        cout << "konnte nicht gefunden.\n";
        return false;
    }
}

bool Tree::helpSearch(TreeNode* ptr,std::string name) {
    //Case: empty tree
    if (ptr == nullptr) {
        return 0;
    }

    if (ptr->getName() == name) {
        ptr->print();
        
        return true;
    }
    
    return helpSearch(ptr->getLeft(), name) || helpSearch(ptr->getRight(), name);
}

void Tree::printAll() {

    cout << left << setw(4) << " ID";
    cout << left << setw(19) << "| Name";
    cout << left << setw(8) << "| Age";
    cout << left << setw(12) << "| Income";
    cout << left << setw(11) << "| PostCode";
    cout << left << setw(7) << "| OrderID\n";

    cout << right << setfill('-');
    cout << setw(5) << "+";
    cout << setw(19) << "+";
    cout << setw(8) << "+";
    cout << setw(12) << "+";
    cout << setw(11) << "+";
    cout << setw(7) << "-" << endl;

    printPreOrder(m_anker);

}

void Tree::printInOrder(TreeNode* ptr) {
    //Case: empty tree
    if (ptr == nullptr) {
        cout << "Leerer Baum." << endl;
       
        return;
    }
    //LWR
    if (ptr->getLeft() != nullptr) {
        printPreOrder(ptr->getLeft());
    }

    cout << setfill(' ');
    cout << setw(4) << ptr->getNodeChronologicalID() << "|";
    cout << setw(18) << ptr->getName() << "|";
    cout << setw(7) << ptr->getAge() << "|";
    cout << setw(11) << ptr->getIncome() << "|";
    cout << setw(10) << ptr->getPostCode() << "|";
    cout << setw(6) << ptr->getNodeOrderID() << endl;

    if (ptr->getRight() != nullptr) {
        printPreOrder(ptr->getRight());
    }
  
}

void Tree::printPreOrder(TreeNode* ptr) {
    //Case: empty tree
    if (ptr == nullptr) {
        cout << "Leerer Baum." << endl;
        return;
    }
    //WLR
    cout << setfill(' ');
    cout << setw(4) << ptr->getNodeChronologicalID() << "|";
    cout << setw(18) << ptr->getName() << "|";
    cout << setw(7) << ptr->getAge() << "|";
    cout << setw(11) << ptr->getIncome() << "|";
    cout << setw(10) << ptr->getPostCode() << "|";
    cout << setw(6) << ptr->getNodeOrderID() << endl;

    if (ptr->getLeft() != nullptr) {
        printPreOrder(ptr->getLeft());
    }

    if (ptr->getRight() != nullptr) {
        printPreOrder(ptr->getRight());
    }

}

void Tree::printPostOrder(TreeNode* ptr) {
    //Case: empty tree
    if (ptr == nullptr) {
        cout << "Leerer Baum." << endl;
        return;
    }
    //LRW
    if (ptr->getLeft() != nullptr) {
        printPreOrder(ptr->getLeft());
    }

    if (ptr->getRight() != nullptr) {
        printPreOrder(ptr->getRight());
    }

    cout << setfill(' ');
    cout << setw(4) << ptr->getNodeChronologicalID() << "|";
    cout << setw(18) << ptr->getName() << "|";
    cout << setw(7) << ptr->getAge() << "|";
    cout << setw(11) << ptr->getIncome() << "|";
    cout << setw(10) << ptr->getPostCode() << "|";
    cout << setw(6) << ptr->getNodeOrderID() << endl;
  
}

void Tree::levelOrder() {
    int maxtief = 10;
    cout << left << setw(4) << " ID";
    cout << left << setw(19) << "| Name";
    cout << left << setw(8) << "| Age";
    cout << left << setw(12) << "| Income";
    cout << left << setw(11) << "| PostCode";
    cout << left << setw(7) << "| OrderID";
    cout << left << setw(6) << "| Level\n";

    cout <<right << setfill('-');
    cout << setw(5) << "+";
    cout << setw(19) << "+";
    cout << setw(8) << "+";
    cout << setw(12) << "+";
    cout << setw(11) << "+";
    cout << setw(9) << "+";
    cout << setw(6) <<"-"<< endl;

    for (int i = 1; i <= maxtief; i++) {
        helpLO(m_anker, i, i);
    }
}

void Tree::helpLO(TreeNode* ptr, int lvl,int ind) {
    //Case: empty tree
    if (ptr == nullptr) {
        cout << "Leerer Baum." << endl;
       
        return;
  
    } else {
        if (ind == 1) {
            cout << setfill(' ');
            cout << setw(4) << ptr->getNodeChronologicalID() << "|";
            cout << setw(18) << ptr->getName() << "|";
            cout << setw(7) << ptr->getAge() << "|";
            cout << setw(11) << ptr->getIncome() << "|";
            cout << setw(10) << ptr->getPostCode() << "|";
            cout << setw(8) << ptr->getNodeOrderID() << "|";
            cout << setw(5) << lvl << endl;
      
        } else if (ind > 1) {
            if (ptr->getLeft() != nullptr) {
                helpLO(ptr->getLeft(), lvl, ind - 1);
            }

            if (ptr->getRight() != nullptr) {
                helpLO(ptr->getRight(), lvl, ind - 1);
            }
        }
    }
}
//
////////////////////////////////////
