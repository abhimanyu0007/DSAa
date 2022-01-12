#include<iostream>
using namespace std;
struct node{
	int data;
	node* next;
};

class list{
	public:
		node* head=0,*nn,*temp;
		void insert(int new_value){
			nn=new node();
			nn->data=new_value;
			nn->next=0;
			if(head==0){
				head=temp=nn;
			}
			else{
				temp->next=nn;
				temp=nn;
			}
			temp->next=head;
		    
		}
	
		void display(){
			temp=head;
			while(temp->next!=head){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<temp->data<<endl;
			
			//below code is for verification
			/*temp=temp->next;
			cout<<temp->data;*/
		
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
