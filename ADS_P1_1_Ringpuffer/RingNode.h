/*************************************************
* ADS Praktikum 1.1
* RingNode.h
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#pragma once
#include <string>

class RingNode {
	
private:
	//
	int m_oldAge = 0;
   	std::string m_description;
   	std::string m_symbolicData;
   	RingNode* m_next;
	//	
public:
	//
	RingNode();
   	RingNode(int oldAge, std::string description, std::string symbolicData);
  
   	int getOldAge();
   	void setOldAge(int oldAge);
  
   	std::string getDescription();
   	void setDescription(std::string description);
  
   	std::string getSymbolicData();
   	void setSymbolicData(std::string symbolicData);
  
   	RingNode* getNext();
   	void setNext(RingNode* next);
	//
};
