#pragma once
#include <iostream>
using namespace std;
class Node
{
private:
    int key;
    int weight;
    Node* lchild;
    Node* rchild;
    Node* child1;
    Node* child2;
public:
    Node(int k);
    ~Node();
    Node* insertR(int k);
    Node* insertI(int k);
    void inOrder();
    bool searchI(int k);
    bool searchR(int k);
	friend ostream& operator<<(ostream& os,Node* n);
	friend istream& operator>>(istream& is,Node* n);
};
