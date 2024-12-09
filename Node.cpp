#include "Node.hpp"
#include <iostream>
using namespace std;
ostream& operator<<(ostream& os,Node* n){
	os<<"Key: "<<n->key<<endl;
	os<<"Weight: "<<n->weight<<endl;
	os<<"Left Child: ";
	if(n->lchild==nullptr){
		os<<"/"<<endl;
	}else os<<n->lchild->key<<endl;
	os<<"Right Child: ";
	if(n->rchild==nullptr){
		os<<"/"<<endl;
	}else os<<n->rchild->key<<endl;
	return os;
}
istream& operator>>(istream& is,Node* n){
	cout<<"Key: ";
	is>>n->key;
	n->lchild=nullptr;
	n->rchild=nullptr;
	return is;
}
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
        } else return this->rchild->insertR(k);
	}
	return nullptr;
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
	return nullptr;
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
            } else return false;
        } else if(k > f->key) { 
            if(f->rchild != nullptr) {
                f = f->rchild;
                continue;
            } else return false;
        }
	}
	return false;
}
bool Node::searchR(int k)
{
    if(k == this->key) {
        return true;
    } else if(k < this->key) {
        if(this->lchild != nullptr) {
            return this->lchild->searchR(k);
        } else return false;
    } else if(k > this->key) {
        if(this->rchild != nullptr) {
            return this->rchild->searchR(k);
		} else return false;
	}
    return false;
}
Node* Node::deleteNode(int k){
    if (this == nullptr) {
        cout << "non e' presente" << endl;
        return nullptr;
    }
    if(this->key==k){
        if (this->lchild == nullptr && this->rchild == nullptr) {
            delete this;
            return nullptr;
        }
        else {
            if (this->lchild == nullptr) {
                int temp = this->key;
                this->key = this->rchild->key;
                this->rchild->key=temp;
                return this->deleteNode(this->key);
            } else if (this->rchild == nullptr) {
                int temp = this->key;
                this->key = this->lchild->key;
                this->lchild->key=temp;
                return this->deleteNode(this->key);
            } else {
                Node* c = this->rchild;
                while (c->lchild != nullptr) {
                    c = c->lchild;
                }
                this->key = c->key;
                return this->rchild->deleteNode(c->key);
            }
        }
    }
    else if (k < this->key) {
        return this->lchild->deleteNode(k);
    } else if (k > this->key) {
        return this->rchild->deleteNode(k);
    }
}
void Node::Preorder(){
	cout<<this->key<<endl;
	if(this->lchild!=nullptr){
		Preordertraversal(this->lchild);
	}
	if(this->rchild!=nullptr){
		Preordertraversal(this->rchild);
	}
}
void Node::Inorder(){
	if(this->lchild!=nullptr){
		Inordertraversal(this->lchild);
	}
	if(this->rchild!=nullptr){
		Inordertraversal(this->rchild);
	}
	cout<<this->key<<endl;
}