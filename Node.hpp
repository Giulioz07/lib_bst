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
public:
    Node(int k);
    ~Node();
    Node* insertR(int k);
    Node* insertI(int k);
    void Inorder();
    bool searchI(int k);
    bool searchR(int k);
	Node* deleteNode(int k);
	void Preorder();
	void Postorder();
	bool isBST();
	friend ostream& operator<<(ostream& os,Node* n);
	friend istream& operator>>(istream& is,Node* n);
};
