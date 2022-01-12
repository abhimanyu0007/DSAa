#include<iostream>
using namespace std;
struct node{
	int data;
	node* next;
	node* prev;
};

class list{
	public:
		node* head=0,*nn,*tail;
		void insert(int new_value){
			nn=new node;
			nn->data=new_value;
			nn->next=0;
			nn->prev=0;
			
			if(head==0){
				head=tail=nn;
				head->next=head;
				head->prev=head;
			}
			else{
				tail->next=nn;
				nn->prev=tail;
				nn->next=head;
				head->prev=nn;
				tail=nn;
			}
		}
		
		void display(){
			node* temp=head;
			do{
				cout<<temp->data<<" ";
				temp=temp->next;
			}while(temp!=head);
			//also you can write temp!=tail, but you need to put onemore cout
		}
};

int main(){
	list obj;
	int k,j;
	cout<<"how many: ";
	cin>>j;
	for(int i=0;i<j;i++){
		cout<<"enter element: ";
		cin>>k;
		obj.insert(k);
	}
	obj.display();
	return 0;
}
