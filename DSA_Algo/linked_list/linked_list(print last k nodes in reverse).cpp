/*
#include<iostream>
using namespace std;
class stud{
	public:
		int age;
		void setage(int num){
			age =num;
		}
		void display(){
			int c=age;
			cout<<c;
		}
};
int main(){
	stud obj;
	obj.setage(20);
	obj.display();
}*/

#include<iostream>
using namespace std;

struct node{
	int data;
	node *next;
};

class list{
	public:
		node *head=0,*temp,*nn;
		int c;
		void insert(int new_value){
			nn=new node();
			nn->data=new_value;
			nn->next=NULL;
			if(head==0){
				head=temp=nn;
			}
			else{
				temp->next=nn;
				temp=nn;
			}
		}
		
		void nnode(int pos){
			c=0;
			temp=head;
			while(temp->next!=0){
				c++;
				temp=temp->next;	
			}
			c=c-pos+1;
			int z=0;
			temp=head;
			while(z<c){
				cout<<temp->data<<" ";
				temp=temp->next;
				z++;
			}
			head=temp;
		}
		
		void reverse(){
			node* curr,*nextn;
			node* prev=0;
			curr=head;
			while(nextn!=0){
				nextn=curr->next;
				curr->next=prev;
				prev=curr;
				curr=nextn;
			}
			head=prev;
			temp=head;
			while(temp!=0){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			
		}
		
		/*void display(){
			int z=0;
			temp=head;
			while(temp!=0 && z<c){
				cout<<temp->data<<" ";
				temp=temp->next;
				z++;
			}
			head=temp;
			/*head=temp;
			//below for reverse
			node* curr,*nextn;
			node* prev=0;
			curr=head;
			while(nextn!=0){
				nextn=curr->next;
				curr->next=prev;
				prev=curr;
				curr=nextn;
				
			}
			head=prev;******
			
			temp=head;
			while(temp!=0){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
		}*/
};
int main(){
	list obj;
	int n,k,p;
	cout<<"how many: ";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"enter num: ";
		cin>>k;
		obj.insert(k);
	}
	cout<<"enter position: ";
	cin>>p;
	obj.nnode(p);
	obj.reverse();
	//obj.display();
	return 0;
	
}

