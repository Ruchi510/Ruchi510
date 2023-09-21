#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* next;
		
	node(int d){
		data=d;
		next=NULL;
	}
};

int lengthLL(node*head){
	int ans=0;
	while(head){
		head=head->next;
		ans++;
	}
	return ans;
}

void insertAtFront(node* &head,node* &tail,int data){
	if(head==NULL){
		node*n=new node(data);
		head=tail=n;
	}
	else{
		node*n=new node(data);
		n->next=head;
		head=n;
	}
}

void insertAtEnd(node* &head,node* &tail,int data){
	if(head==NULL){
		node*n=new node(data);
		head=tail=n;
	}
	else{
		node*n=new node(data);
		tail->next=n;
		tail=n;
	}
}

void insertAtMiddle(node*&head,node*&tail,int data,int pos){
	if(pos>=lengthLL(head)){
		insertAtEnd(head,tail,data);
	}
	else if(pos==0){
		insertAtFront(head,tail,data);
	}
	else{
		node*temp=head;
		for(int i=1;i<pos;i++){
			temp=temp->next;
		}
		node*n=new node(data);
		n->next=temp->next;
		temp->next=n;
	}
}

void reverseLL(node*&head,node*&tail){
	node*c=head,*p=NULL;
	node*n;
	while(c!=NULL){
		n=c->next;
		c->next=p;
		p=c;
		c=n;
	}
	swap(head,tail);
}

void revreseaLLRec(node*&head,node*p=NULL){
	//base case
	if(head==NULL){
		return;
	}
	//recursive case
	node*n=head->next;
	head->next=p;
	revreseaLLRec(n,head);

}

void printLL(node*head){
	while(head!=NULL){
		cout<<head->data<<"-->";
		head=head->next;
	}
	cout<<"NULL\n"<<endl;

}

int main(){
	node*head;
	node*tail;
	head=tail=NULL;
	insertAtFront(head,tail,1);
	insertAtFront(head,tail,2);
	insertAtFront(head,tail,3);
	insertAtFront(head,tail,4);
	insertAtFront(head,tail,5);
	
	cout<<"Length of LL: "<<lengthLL(head)<<endl;
	
	//printLL(head);
	//reverseLL(head,tail);
	//printLL(head);

	revreseaLLRec(head);
	swap(head,tail);
	printLL(head);

	return 0;
}

