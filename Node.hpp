#pragma once
class Node
{
private:
    int key;
    int weight;
<<<<<<< HEAD
    Node* lchild;
    Node* rchild;
=======
    Node* child1;
    Node* child2;
>>>>>>> e820ea0bc6a91fa09d2d053fb864c299dc7db261

public:
    Node(int k);
    ~Node();
    Node* insertR(int k);
    Node* insertI(int k);
    void inOrder();
    bool searchI(int k);
    bool searchR(int k);
};
