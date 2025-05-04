/*************************************************
 * ADS Praktikum 1.2
 * TreeNode.h
 * Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
 *************************************************/
#pragma once
#include <string>

using namespace std;

class TreeNode {

private:
    ///////////////////////////////////////
    // Ihr Code hier:
    int m_NodeOrderID;
    int m_NodeChronologicalID;
    string m_Name;
    int m_Age;
    double m_Income;
    int m_PostCode;
    TreeNode* m_left = nullptr;
    TreeNode* m_right = nullptr;
    //
    ////////////////////////////////////

public:
    ///////////////////////////////////////
    // Ihr Code hier:
    TreeNode(int NodeOrderID, int NodeChronologicalID, string Name, int Age, double Income, int PostCode);

    int getNodeOrderID();
    void setNodeOrderID(int nodeOrder);

    int getNodeChronologicalID();
    void setNodeChronologicalID(int nodeChronological);

    string getName();
    void setName(string name);

    int getAge();
    void setAge(int age);

    double getIncome();
    void setIncome(double income);

    int getPostCode();
    void setPostCode(int postcode);

    TreeNode* getRight();
    void setRight(TreeNode* right);

    TreeNode* getLeft();
    void setLeft(TreeNode* left);

    void print();
    //
    ////////////////////////////////////
};
