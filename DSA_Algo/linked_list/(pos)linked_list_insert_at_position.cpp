#include<iostream>
using namespace std;

struct node{
	int data;
	node* next;
};

class list{
	public:
		node* head=0,*nn,*temp;
		
		
		void insert(int value){
			nn= new node();
			nn->data=value;
			nn->next=0;
			
			if(head==0){
				head=temp=nn;
			}
			else{
				temp->next=nn;
				temp=nn;
				
			}
		}
		
		void insert_position(int value,int pos){
			
			if(pos==0){
				//count++;
				nn=new node();
				nn->data=value;
				nn->next=head;
				head=nn;
			}
			else{
			
				int z=1;
				temp=head;
				while(z<pos-1){
					temp=temp->next;
					z++;
				}
				nn=new node();
				nn->data=value;
				//first update nn->next then temp->next refer jenny youtube 26:08
				
				//to insert at beginning refer insertion at beginning here at line 32 temp=temp->next so insertion go next to first node
				nn->next=temp->next;
				temp->next=nn;
			}
			
		}
		int display(){
			temp=head;
			while(temp!=0){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
		}
};

int main(){
	list obj;
	int k,j,pos;
	cout<<"how many: ";
	cin>>j;
	//below for loop i=1 to get targeted value otherwise i-1 value will com
	for(int i=0;i<j;i++){
		cout<<"enter element: ";
		cin>>k;
		obj.insert(k);
	}
	
	cout<<"enter position to insert element: ";
	cin>>pos;
	
	cout<<"enter element to insert: ";
	cin>>k;
	obj.insert_position(k,pos);
	obj.display();
	return 0;
}



