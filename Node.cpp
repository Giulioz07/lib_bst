#include "Node.hpp"

#include <iostream>
using namespace std;
Node::Node(int k)
{
    key = k;
    weight = 1;
    lchild = nullptr;
    rchild = nullptr;
}

Node::~Node() {}

Node* Node::insertR(int k)
{
    if(k == this->key) {
        this->weight++;
        cout << "e' gia' presente" << endl;
        return this;
    } else if(k < this->key) {
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
    }
}
Node* Node::insertI(int k)
{
    Node* f = this;
    while(true) {
        if(k < f->key) {
            if(f->lchild == nullptr) {
                f->lchild = new Node(k);
                return f->lchild;
            } else {
                f = f->lchild;
                continue;
            }
        }
        if(k > f->key) {
            if(f->rchild == nullptr) {
                f->rchild = new Node(k);
                return f->rchild;
            } else {
                f = f->rchild;
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
    if(lchild != nullptr) {
        this->lchild->inOrder();
    }
    cout << key << endl;
    if(rchild != nullptr) {
        this->rchild->inOrder();
    }
}

bool Node::searchI(int k)
{
    Node* f = this;
    while(true) {
        if(k == f->key) {
            return true;
        } else if(k < f->key) {
            if(f->lchild != nullptr) {
                f = f->lchild;
                continue;
            } else
                return false;
        } else if(k > f->key) {
            if(f->rchild != nullptr) {
                f = f->rchild;
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
        if(this->lchild != nullptr) {
            return this->lchild->searchR(k);
        } else
            return false;
    } else if(k > this->key) {
        if(this->rchild != nullptr) {
            return this->rchild->searchR(k);
        } else
            return false;
    }
    return false;
}