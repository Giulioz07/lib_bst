#pragma once

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
    void inOrder();
    bool searchI(int k);
    bool searchR(int k);
};
