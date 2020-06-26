#include <iostream>
using namespace std;

class node{
	private:
		int data;
		node *next;
	public:
		friend class list;
};

class list{
	private:
		node *head;
	public:
		list(){
			head=NULL;
		};
		void linsert(int num);
		int ldelete();
		void rinsert(int num);
		int rdelete();
		void show();
};

void list::linsert(int num){
	 node *newnode = new node;
	 newnode->data = num;
	 newnode->next = head;
	 head = newnode;
};

int list::ldelete(){
	if(!head){
		cout<<endl<<"List is empty";
		return -1;
	}
	int t = head->data;
	node *old = head;
	head = head->next;
	delete old;
	return t;	
};

void list::rinsert(int num){
	 node *newnode = new node;
	 newnode->data = num;
	 newnode->next = NULL;
	 if(!head){
	 	head=newnode;
	 	return;
	 }
	 node *cur = head;
	 while(cur->next){
	 	cur = cur->next;
	 }
	 cur->next = newnode;
};

int list::rdelete(){
	if(!head){
		cout<<"List is empty";
		return -1;
	}
	int t;
	if(!head->next){
		t = head->data;
		delete head;
		return t;
	}
	node*cur = head;
	while(cur->next->next){
		cur = cur->next;
	}
	t = cur->next->data;
	delete cur->next;
	cur->next = NULL;
	return t;
};

void list::show(){
	 if(!head){
	 	cout<<"List is empty";
	 	return;
	 }	
	 node *cur = head;
	 while(cur){
	 	cout<<cur->data<<" ";
	 	cur = cur->next;
	 }
};

int main(){
	int done = 0, opt;
	int n;
	list l1;
	while(!done){
		cout<<endl<<"Select option : "
		    <<endl<<"1. L-Insert"
		    <<endl<<"2. L-Delete"
		    <<endl<<"3. R-Insert"
		    <<endl<<"4. R-Delete"
		    <<endl<<"5. Show"
		    <<endl<<"Default. Done"<<endl;
		cin>>opt;
		switch(opt){
			case 1: cout<<"Enter number : ";
				 	cin>>n;
				 	l1.linsert(n);break;
			case 2: n = l1.ldelete();
				 	cout<<endl<<n; break;
			case 3: cout<<"Enter number : ";
				 	cin>>n;
				 	l1.rinsert(n); break;
			case 4: n = l1.rdelete();
				 	cout<<endl<<n; break;
			case 5: l1.show(); break;
			default : done = 1;		 	
		};
	}
	return 0;
}
