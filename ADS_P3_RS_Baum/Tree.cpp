#include "Tree.h"
#include "TreeNode.h"
#include <iostream>
#include <iomanip>
#include <queue>

Tree::Tree()
	: m_anker{ nullptr }
	, m_CurrentNodeChronologicalID{ -1 }
{}

Tree::~Tree(){
	
}

/**
 * Rekursive Hilfsfunktion f�r die Suche nach einem Knoten mittels Namensvergleich.
 * Da der Name kein Alleinstellungsmerkmal ist, muss der gesamte Baum in Preorder durchlaufen und gepr�ft werden.
 * Eine Score ermittelt die Fundh�ufigkeit eines Namens.
 *
 * \param[in] node Aktueller Knoten im Baum
 * \param[in] Name String nach dem gesucht wird
 * \param[out] score Anzahl der gefundenen Knoten mit entsprechendem Namen
 */
void searchNode_RecHelper(TreeNode* node, std::string Name, int &score)
{
	if (node->getName() == Name)
	{
		node->print();
		score++;
	}
	if (node->getLeft() != nullptr)
		searchNode_RecHelper(node->getLeft(), Name, score);
	if (node->getRight() != nullptr)
		searchNode_RecHelper(node->getRight(), Name, score);
}

/**
 * Rekursive Suche nach Knoten (preorder)
 *
 * \string Name Der String der im Baum gesucht werden soll
 */
bool Tree::searchNode(std::string Name) 
{
	if (m_anker == nullptr) return false;
	
	int search_score = 0;
	searchNode_RecHelper(m_anker, Name, search_score);
	
	if(search_score > 0) return true;
	
	return false;
}


/**
 * Ausgabe aller Knoten in Tabellenform Levelorder-BST
 *
 */
void Tree::printAll() //Levelorder-BST
{
	///////////////////////////////////////
	// Ihr Code hier:
	std::cout << std::left << std::setw(4) << " ID";
	std::cout << std::left << std::setw(19) << "| Name";
	std::cout << std::left << std::setw(8) << "| Age";
	std::cout << std::left << std::setw(12) << "| Income";
	std::cout << std::left << std::setw(11) << "| PostCode";
	std::cout << std::left << std::setw(7) << "| OrderID";
	std::cout << std::left << std::setw(7) << "| Red\n";


	std::cout << std::right << std::setfill('-');
	std::cout << std::setw(5) << "+";
	std::cout << std::setw(19) << "+";
	std::cout << std::setw(8) << "+";
	std::cout << std::setw(12) << "+";
	std::cout << std::setw(11) << "+";
	std::cout << std::setw(8) << "+";
	std::cout << std::setw(7) << "-" << std::endl;
	preOrder(m_anker);
	//
	///////////////////////////////////////
}

void Tree::preOrder(TreeNode* ptr) {
	if (ptr == 0) {
		std::cout << "Baum ist Leer." << std::endl;
		return;
	}
	std::cout << std::setfill(' ');
	std::cout << std::setw(4) << ptr->getNodeChronologicalID() << "|";
	std::cout << std::setw(18) << ptr->getName() << "|";
	std::cout << std::setw(7) << ptr->getAge() << "|";
	std::cout << std::setw(11) << ptr->getIncome() << "|";
	std::cout << std::setw(10) << ptr->getPostCode() << "|";
	std::cout << std::setw(8) << ptr->getNodeOrderID() << "|";
	std::cout << std::setw(6) << ptr->getRed() << std::endl;
	if (ptr->getRight() != 0)
		preOrder(ptr->getRight());
	if (ptr->getLeft() != 0)
		preOrder(ptr->getLeft());
}

void Tree::printLvlOrder(){

	std::cout << std::left << std::setw(4) << " ID";
	std::cout << std::left << std::setw(19) << "| Name";
	std::cout << std::left << std::setw(8) << "| Age";
	std::cout << std::left << std::setw(12) << "| Income";
	std::cout << std::left << std::setw(11) << "| PostCode";
	std::cout << std::left << std::setw(7) << "| OrderID";
	std::cout << std::left << std::setw(7) << "| Red\n";


	std::cout << std::right << std::setfill('-');
	std::cout << std::setw(5) << "+";
	std::cout << std::setw(19) << "+";
	std::cout << std::setw(8) << "+";
	std::cout << std::setw(12) << "+";
	std::cout << std::setw(11) << "+";
	std::cout << std::setw(8) << "+";
	std::cout << std::setw(7) << "-" << std::endl;
	lvlOrder(m_anker);
}

void Tree::lvlOrder(TreeNode* node){
	std::queue<TreeNode*> q;
	if (node == 0) {
		std::cout << "Baum ist Leer." << std::endl;
		return;
	}
	q.push(node);
	TreeNode* tmp = node;
	while (!q.empty()) {
		int count = q.size();
		while (count > 0) {
			tmp = q.front();
			std::cout << std::setfill(' ');
			std::cout << std::setw(4) << tmp->getNodeChronologicalID() << "|";
			std::cout << std::setw(18) << tmp->getName() << "|";
			std::cout << std::setw(7) << tmp->getAge() << "|";
			std::cout << std::setw(11) << tmp->getIncome() << "|";
			std::cout << std::setw(10) << tmp->getPostCode() << "|";
			std::cout << std::setw(8) << tmp->getNodeOrderID() << "|";
			std::cout << std::setw(6) << tmp->getRed() << std::endl;
			if (tmp->getLeft())
				q.push(tmp->getLeft());
			if (tmp->getRight())
				q.push(tmp->getRight());
			
			q.pop();
			count--;
		}
	}
}

void Tree::printLevelOrder(){
	std::queue<TreeNode*> q;
	int niveau=0;

	if(m_anker==nullptr){
		std::cout<<"Leerer Baum."<<std::endl;
		return;
	}else{
		q.push(m_anker);
		TreeNode* ptr=m_anker;
		while(!q.empty()){
			int count=q.size();
			std::cout<<"Niveau "<<niveau<<" : ";
			while(count>0){
				ptr=q.front();
				if(ptr->getLeft()){
					if(!ptr->getLeft()->getRed()){
						q.push(ptr->getLeft());
						std::cout<<"(";
					}
					else{
						if(ptr->getLeft()->getLeft()!=nullptr){
							q.push(ptr->getLeft()->getLeft());
						}
						if(ptr->getLeft()->getRight()){
							q.push(ptr->getLeft()->getRight());
						}
						std::cout<<"("<<ptr->getLeft()->getNodeOrderID()<<", ";
					}
				}
				else std::cout<<"(";


				std::cout<<ptr->getNodeOrderID();

				if(ptr->getRight()){
					if(!ptr->getRight()->getRed()){
						q.push(ptr->getRight());
						std::cout<<")";

					}else{
						if(ptr->getRight()->getLeft()){
							q.push(ptr->getRight()->getLeft());
						}

						if(ptr->getRight()->getRight())
						q.push(ptr->getRight()->getLeft());

						std::cout<<", "<<ptr->getRight()->getNodeOrderID()<<")";
					}
					
				}else std::cout<<")";

				q.pop();
				count--;
			}
			niveau++;
			std::cout<<std::endl;
		}
	}
}
void Tree::printLevelOrder(int lvl){
	std::queue<TreeNode*> q;
	int niv = 0;

	if (m_anker == 0) {
		std::cout << "Baum ist Leer." << std::endl;
		return;
	}
	q.push(m_anker);
	TreeNode* Ptr = m_anker;
	while (!q.empty()) {
		int count = q.size();
		if (niv == lvl)
			std::cout << "Niveau " << niv << ": ";
		while (count > 0) {
			Ptr = q.front();
			if (Ptr->getLeft()) {
				if (!Ptr->getLeft()->getRed()) {
					q.push(Ptr->getLeft());
					if (niv == lvl)
						std::cout << "(";
				}
				else {
					if (Ptr->getLeft()->getLeft())
						q.push(Ptr->getLeft()->getLeft());

					if (Ptr->getLeft()->getRight())
						q.push(Ptr->getLeft()->getRight());
					if (niv == lvl)
						std::cout << "(" << Ptr->getLeft()->getNodeOrderID() << ", ";
				}
			}
			else {
				if (niv == lvl)
					std::cout << "(";
			}
			if (niv == lvl)
				std::cout << Ptr->getNodeOrderID();
			if (Ptr->getRight()) {
				if (!Ptr->getRight()->getRed()) {
					q.push(Ptr->getRight());
					if (niv == lvl)
						std::cout << ")";
				}
				else {
					if (Ptr->getRight()->getLeft())
						q.push(Ptr->getRight()->getLeft());

					if (Ptr->getRight()->getRight())
						q.push(Ptr->getRight()->getRight());
					if (niv == lvl)
						std::cout << ", " << Ptr->getRight()->getNodeOrderID() << ")";
				}
			}
			else
				if (niv == lvl)
					std::cout << ")";
			q.pop();
			count--;
		}
		niv++;
		std::cout << std::endl;
	}
}


bool Tree::rotateTreeRight(TreeNode* p1, TreeNode* p2) {
	if (p1 == m_anker){
		m_anker = p2;
		p2->setParent(0);
	}
	else {
		TreeNode* prnt = p1->getParent();
		if (prnt->getNodeOrderID() > p2->getNodeOrderID()) {
			prnt->setLeft(p2);
			p2->setParent(prnt);
		}
		else {
			prnt->setRight(p2);
			p2->setParent(prnt);
		}
	}
	p1->setParent(p2);
	p1->setLeft(p2->getRight());
	if (p1->getLeft() != nullptr)
		p1->getLeft()->setParent(p1);
	p2->setRight(p1);
	return 1;
}

bool Tree::rotateTreeLeft(TreeNode* p1, TreeNode* p2) {
	if (p1 == m_anker) {
		m_anker = p2;
		p2->setParent(0);
	}
	else {
		TreeNode* prnt = p1->getParent();
		if (prnt->getNodeOrderID() > p2->getNodeOrderID()) {
			prnt->setLeft(p2);
			p2->setParent(prnt);
		}
		else {
			prnt->setRight(p2);
			p2->setParent(prnt);
		}
	}
	p1->setParent(p2);
	p1->setRight(p2->getLeft());
	if (p1->getRight() != 0)
		p1->getRight()->setParent(p1);
	p2->setLeft(p1);
	return 1;
}

void Tree::balance(TreeNode* node){
	//kanan belok kiri
	if(node->getParent()!=nullptr && node->getLeft()!=nullptr){
		if(node->getNodeOrderID() > node->getParent()->getNodeOrderID() && node->getLeft()->getRed()){
			rotateTreeRight(node,node->getLeft());
			rotateTreeLeft(node->getParent()->getParent(),node->getParent());
			node->getParent()->setRed(0);
			node->getParent()->getLeft()->setRed(1);
			return;
		}
	}

	//kiri belok kanan
	if(node->getParent()!=nullptr && node->getRight()!=nullptr){
		if(node->getNodeOrderID()<node->getParent()->getNodeOrderID() && node->getRight()->getRed()){
			rotateTreeLeft(node,node->getRight());
			rotateTreeRight(node->getParent()->getParent(), node->getParent());
			node->getParent()->setRed(0);
			node->getParent()->getRight()->setRed(1);
			return;
		}
	}

	//kiri ke kiri
	if(node->getParent()!=nullptr && node->getLeft()!=nullptr){
		if(node->getNodeOrderID()<node->getParent()->getNodeOrderID() && node->getLeft()->getRed()){
			rotateTreeRight(node->getParent(),node);
			node->setRed(0);
			node->getRight()->setRed(1);
			return;
		}
	}

	//kanan ke kanan
	if(node->getParent()!=nullptr && node->getRight()!= nullptr){
		if(node->getNodeOrderID() > node->getParent()->getNodeOrderID() && node->getRight()->getRed()){
			rotateTreeLeft(node->getParent(),node);
			node->setRed(0);
			node->getLeft()->setRed(1);
			return;
		}
	}
}

bool Tree::split4Node(TreeNode* node){
	if(m_anker==nullptr) {
		std::cout<<"Leerer Baum."<<std::endl;
		return false;
	}else{
		//when node red
		if(node->getRed()) return false;


		if(node->getLeft()!=nullptr && node->getRight()!=nullptr){
		//when both Nachfolger red
			if(node->getLeft()->getRed() && node->getRight()->getRed()){
				if(m_anker!=node)
					node->setRed(1);

				node->getLeft()->setRed(0);
				node->getRight()->setRed(0);
				return true;
			}
		}	
		return false;
		


	}
}
bool Tree::addNode(std::string Name, int Age, double Income, int PostCode){
	int OrderID = Age + Income + PostCode;
        TreeNode* NewNode = new TreeNode(OrderID, ++m_CurrentNodeChronologicalID, Name, Age, Income, PostCode);

	if(m_anker==nullptr){
		m_anker=NewNode;
		m_anker->setRed(0);
	}
	else{
		TreeNode* current=m_anker;
		TreeNode* parent=nullptr;

		do{
			split4Node(current);
			parent=current;
			
			if(NewNode->getNodeOrderID()>=current->getNodeOrderID()){
				current=current->getRight();
			}
			else current=current->getLeft();
		}while(current!=nullptr);
		NewNode->setParent(parent);
		if(NewNode->getNodeOrderID()<parent->getNodeOrderID()){
			parent->setLeft(NewNode);
		}else
			parent->setRight(NewNode);
	}

	TreeNode* p1=NewNode;
	int redCounter=0;
	while(p1!=nullptr){
		if(p1->getRed()==false){
			redCounter=0;
		}
		else {
			redCounter++;
		}

		if(redCounter==2){
			balance(p1);
		}
		p1=p1->getParent();
	}

	return 1;
}


int Tree::proofRBCriterion(TreeNode* node) {
    if(node == nullptr){
        return -1;      //Base Case: Empty tree, return -1
    }

    int leftHeight = 0;
    int rightHeight = 0;
    if(node->getLeft() != nullptr){
        leftHeight = proofRBCriterion(node->getLeft());
    }
    if(node->getRight() != nullptr){
        rightHeight = proofRBCriterion(node->getRight());
    }

    //Case 1, both successors do not exist: then a leaf node is found, the height 0 is returned
    if(node->getLeft() == nullptr && node->getRight() == nullptr){
        return 0;
    }

    //Case 2, both successors are red: the heights of the red nodes must match the height of the black parent.
    if(node->getLeft() != nullptr && node->getLeft()->getRed() == true && node->getRight() != nullptr && node->getRight()->getRed() == true){
        if(leftHeight == rightHeight){
            return 1;
        } else {
            return -1;
        }
    }

    //Case 3, one of the successors is red, the other is black: the height of the red node must be one higher 
    // than the height of the black successor node and is the same with the height of the black parent node.
    if(node->getLeft() != nullptr && node->getLeft()->getRed() == true && node->getRight() != nullptr && node->getRight()->getRed() == false){
        if(leftHeight + 1 == rightHeight){
            return 1;
        } else {
            return -1;
        }
    }

    if(node->getLeft() != nullptr && node->getLeft()->getRed() == false && node->getRight() != nullptr && node->getRight()->getRed() == true){
        if(rightHeight + 1 == leftHeight){
            return 1;
        } else {
            return -1;
        }
    }

    //Case 4, both successors are black: the heights of the black nodes must be the same and 
    // returns the height of the black successor node + 1.
    if(node->getLeft() != nullptr && node->getLeft()->getRed() == false && node->getRight() != nullptr && node->getRight()->getRed() == false){
        if(rightHeight == leftHeight){
            return leftHeight + 1;
        } else {
            return -1;
        }
    }

    //Case 5, if one of the successors does not exist, the height of the other node is used: 
    // for the black successor node the height + 1, for the red successor node the same height is returned. 
    if(node->getLeft() == nullptr){
        if(node->getRight()->getRed()){
            return rightHeight;
        }
        return rightHeight + 1;
    } else if(node->getRight() == nullptr){
        if(node->getLeft()->getRed()){
            return leftHeight;
        }
        return leftHeight + 1;
    }

    //Case 6, if an error is detected, -1 should be returned and the recursive method cancelled.
    return -1;
}
