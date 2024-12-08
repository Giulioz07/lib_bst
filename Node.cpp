#include "Node.hpp"

#include <iostream>
using namespace std;
Node::Node(int k)
{
    key = k;
    weight = 1;
<<<<<<< HEAD
    lchild = nullptr;
    rchild = nullptr;
=======
    child1 = nullptr;
    child2 = nullptr;
>>>>>>> e820ea0bc6a91fa09d2d053fb864c299dc7db261
}

Node::~Node() {}

Node* Node::insertR(int k)
{
    if(k == this->key) {
        this->weight++;
        cout << "e' gia' presente" << endl;
        return this;
    } else if(k < this->key) {
<<<<<<< HEAD
        if(this->lchild == nullptr) {
            this->lchild = new Node(k);
            return this->lchild;
        } else
            return this->lchild->insertR(k);
        ;
    } else if(k > this->key) {
        if(this->rchild == nullptr) {
            this->rchild = new Node(k);
            return this->rchild;
        } else
            return this->rchild->insertR(k);
=======
        if(this->child1 == nullptr) {
            this->child1 = new Node(k);
            return this->child1;
        } else
            return this->child1->insertR(k);
        ;
    } else if(k > this->key) {
        if(this->child2 == nullptr) {
            this->child1 = new Node(k);
            return this->child2;
        } else
            return this->child2->insertR(k);
>>>>>>> e820ea0bc6a91fa09d2d053fb864c299dc7db261
    }
}
Node* Node::insertI(int k)
{
    Node* f = this;
    while(true) {
        if(k < f->key) {
<<<<<<< HEAD
            if(f->lchild == nullptr) {
                f->lchild = new Node(k);
                return f->lchild;
            } else {
                f = f->lchild;
=======
            if(f->child1 == nullptr) {
                f->child1 = new Node(k);
                return f->child1;
            } else {
                f = f->child1;
>>>>>>> e820ea0bc6a91fa09d2d053fb864c299dc7db261
                continue;
            }
        }
        if(k > f->key) {
<<<<<<< HEAD
            if(f->rchild == nullptr) {
                f->rchild = new Node(k);
                return f->rchild;
            } else {
                f = f->rchild;
=======
            if(f->child2 == nullptr) {
                f->child2 = new Node(k);
                return f->child2;
            } else {
                f = f->child2;
>>>>>>> e820ea0bc6a91fa09d2d053fb864c299dc7db261
                continue;
            }
        } else {
            f->weight++;
            cout << "e' gia' presente" << endl;
            return f;
        }
    }
}
void Node::inOrder()
{
<<<<<<< HEAD
    if(lchild != nullptr) {
        this->lchild->inOrder();
    }
    cout << key << endl;
    if(rchild != nullptr) {
        this->rchild->inOrder();
=======
    if(child1 != nullptr) {
        this->child1->inOrder();
    }
    cout << key << endl;
    if(child2 != nullptr) {
        this->child2->inOrder();
>>>>>>> e820ea0bc6a91fa09d2d053fb864c299dc7db261
    }
}

bool Node::searchI(int k)
{
    Node* f = this;
    while(true) {
        if(k == f->key) {
            return true;
        } else if(k < f->key) {
<<<<<<< HEAD
            if(f->lchild != nullptr) {
                f = f->lchild;
=======
            if(f->child1 != nullptr) {
                f = f->child1;
>>>>>>> e820ea0bc6a91fa09d2d053fb864c299dc7db261
                continue;
            } else
                return false;
        } else if(k > f->key) {
<<<<<<< HEAD
            if(f->rchild != nullptr) {
                f = f->rchild;
=======
            if(f->child2 != nullptr) {
                f = f->child2;
>>>>>>> e820ea0bc6a91fa09d2d053fb864c299dc7db261
                continue;
            } else
                return false;
        }
    }
}
bool Node::searchR(int k)
{
    if(k == this->key) {
        return true;
    } else if(k < this->key) {
<<<<<<< HEAD
        if(this->lchild != nullptr) {
            return this->lchild->searchR(k);
        } else
            return false;
    } else if(k > this->key) {
        if(this->rchild != nullptr) {
            return this->rchild->searchR(k);
=======
        if(this->child1 != nullptr) {
            return this->child1->searchR(k);
        } else
            return false;
    } else if(k > this->key) {
        if(this->child2 != nullptr) {
            return this->child2->searchR(k);
>>>>>>> e820ea0bc6a91fa09d2d053fb864c299dc7db261
        } else
            return false;
    }
    return false;
}