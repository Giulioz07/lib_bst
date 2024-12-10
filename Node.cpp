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
void Node::Inorder()
{
    if(lchild != nullptr) {
        this->lchild->Inorder();
    }
    cout << key << endl;
    if(rchild != nullptr) {
        this->rchild->Inorder();
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
        if (lchild == nullptr && rchild == nullptr) {
            delete this;
            return nullptr;
        }
        if (lchild == nullptr) {
            Node* temp = rchild;
            *this = *temp;
            delete temp;
			return nullptr;
        } else if (rchild == nullptr) {
            Node* temp = lchild;
            *this = *temp;
            delete temp;
			return nullptr;
        } else {
            Node* temp = rchild;
            while (temp->lchild != nullptr) {
                temp = temp->lchild;
            }
            return temp->deleteNode(temp->key);
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
		this->lchild->Preorder();
	}
	if(this->rchild!=nullptr){
		this->rchild->Preorder();
	}
}
void Node::Postorder(){
	if(this->lchild!=nullptr){
		this->lchild->Postorder();
	}
	if(this->rchild!=nullptr){
		this->rchild->Postorder();
	}
	cout<<this->key<<endl;
}
bool Node::isBST() {
        static int prev = INT_MIN;
        if (this == nullptr){
			return true;
		}
        if (lchild->isBST()){
			return true;
		}
        if (key <= prev) {
			return false;
		}
        prev = key;
        return rchild->isBST();
}
