#include<iostream>
using namespace std;

struct node{
	int data;
	node* next;
};

class list{
	public:
		int count=0,value;
		node* head=0,*nn,*temp;
		
		//nn= new node();  don't write this here because statements are written inside function only declaration and definition is possible outside
		
		void insert(int values){
			nn= new node();
			nn->data=values;
			nn->next=0;
			count++;
			
			if(head==0){
				head=temp=nn;
			}
			else{
				temp->next=nn;
				temp=nn;
			}
		}
		
		void insert_begin(int new_value){
			count++;
			nn=new node();
			nn->data=new_value;
			nn->next=head;
			head=nn;
		}
		
		void insert_end(int new_value){
			count++;
			temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			//temp->next=nn;  don't write this statement here bcouz temp->next will point to nn & nn at that time is 5(e.g. 4 elements 2-5) 5's next is null so write this after new node
			nn=new node();
			nn->data= new_value;
			temp->next=nn;         
		}
		
		/*another for insert_end but standard logic is above one
		nn=new node();
		nn->data=new_value;
		temp->next=nn;
		nn->next=0;*/
		
		void display(){
			temp=head;
			while(temp!=0){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<"\ncount is: "<<count;
		}
};

int main(){
	list obj;
	int k,j,b,e;
	cout<<"how many values: ";
	cin>>j;
	for(int i=0;i<j;i++){
		cout<<"enter element: ";
		cin>>k;
		obj.insert(k);
	}
	cout<<"enter element to insert at beginning: ";
	cin>>b;
	obj.insert_begin(b);
	
	cout<<"enter element to insert at end: ";
	cin>>e;
	obj.insert_end(e);
	
	obj.display();
	return 0;
}
