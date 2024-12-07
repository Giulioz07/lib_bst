//libreria di Zaninello Giulio
#include <iostream>
using namespace std;
struct Node {
    int data;
	int weight;
	Node* child1;
	Node* child2;
	Node (int val){
		data=val;
		weight=1;
		child1=child2=nullptr;
	}
};
Node* insertdata(int n, Node *f) {
	if(n == f->data){
		f->weight++;
		cout<<"e' gia' presente"<<endl;
		return f;
	}
  if(n > f->data){
    if(f->child2 == nullptr){
      f->child2 = new Node(n);
    } else {
      insertdata(n, f->child2);
	  return f->child2;
    }
  } else if (n < f->data) {
    if(f->child1 == nullptr){
      f->child1 = new Node(n);
    } else {
      insertdata(n, f->child1);
	  return f->child1;
    }
  }
}
void searchdata(int n,Node *f){
	if(n==f->data){
		cout<<"l' indirizzo di memoria di "<<n<<" e' "<<f<<endl;
		return ;
	}
	if(n<f->data){
		if(f->child1==nullptr){
			cout<<"non e' presente"<<endl;
			return ;
		}
		else searchdata(n,f->child1);
	}
	if(n>f->data){
		if(f->child2==nullptr){
			cout<<"non e' presente"<<endl;
			return ;
		}
		else searchdata(n,f->child2);
	}
}
bool isBST(Node* f, int min=INT_MIN, int max=INT_MAX) {
    if (f==nullptr){
        return true;
    }
    if (f->data<min||f->data>max){
        return false;
    }
    if(isBST(f->child1, min, f->data-1)&&isBST(f->child2, f->data + 1, max)){
		 return true;
	}
	else return false;
}
void canceldata(int n, Node* &f){
    if (f == nullptr) {
        cout << "non e' presente" << endl;
        return;
    }
    if (n < f->data) {
        canceldata(n, f->child1);
    } else if (n > f->data) {
        canceldata(n, f->child2);
    } else {
        if (f->child1 == nullptr && f->child2 == nullptr) {
            delete f;
            f = nullptr;
        } else if (f->child1 == nullptr) {
            Node* temp = f;
            f = f->child2;
            delete temp;
        } else if (f->child2 == nullptr) {
            Node* temp = f;
            f = f->child1;
            delete temp;
        } else {
            Node* c = f->child2;//c è il successivo di f
            while (c->child1 != nullptr) {
                c = c->child1;
            }
            f->data = c->data;
            canceldata(c->data, f->child2);
        }
    }
}
Node* iteractiveinsertdata(int n,Node* f){
	while(true){
		if(n<f->data){
			if(f->child1!=nullptr){
				f=f->child1;
				continue;
			}
			else{
				f->child1=new Node(n);
				return f->child1;
			}
		}
		if(n>f->data){
			if(f->child2!=nullptr){
				f=f->child2;
				continue;
			}
			else{
				f->child2=new Node(n);
				return f->child2;
			}
		}
		if(n==f->data){
			f->weight++;
			cout<<"e' gia' presente"<<endl;
			return f;
		}
	}
}
void iteractivesearchdata(int n,Node *f){
	while(true){
		if(n==f->data){
		cout<<"l' indirizzo di memoria di "<<n<<" e' "<<f<<endl;
		break;
		}
		if(n<f->data){
			if(f->child1==nullptr){
				cout<<"non e' presente"<<endl;
				break;
			}
			else{
				f=f->child1;
				continue;
			}
		}
		if(n>f->data){
			if(f->child2==nullptr){
				cout<<"non e' presente"<<endl;
				break;
			}
			else{
				f=f->child2;
				continue;
			}
		}
	}
}
void Preordertraversal(Node* f){
	cout<<f->data<<endl;
	if(f->child1!=nullptr){
		Preordertraversal(f->child1);
	}
	if(f->child2!=nullptr){
		Preordertraversal(f->child2);
	}
}
void Inordertraversal(Node* f){
	if(f->child1!=nullptr){
		Inordertraversal(f->child1);
	}
	cout<<f->data<<endl;
	if(f->child2!=nullptr){
		Inordertraversal(f->child2);
	}
}
void Postordertraversal(Node* f){
	if(f->child1!=nullptr){
		Postordertraversal(f->child1);
	}
	if(f->child2!=nullptr){
		Postordertraversal(f->child2);
	}
	cout<<f->data<<endl;
}
int heightcalc(Node* f){
	if(f==nullptr){
		return 0;
	}
	int l=heightcalc(f->child1);
	int r=heightcalc(f->child2);
	return max(l,r)+1;
}
Node* createroot(){
	int num;
	cout<<"Inserisci un numero"<<endl;
	cin>>num;
	return new Node (num);
}
void outdata(Node *f){
	Preordertraversal(f);
}


