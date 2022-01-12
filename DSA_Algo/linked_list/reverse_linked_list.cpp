
#include<iostream>
using namespace std;

struct node{
	int data;
	node* next;
};

class list{
	public:
		node* head=0,*nn,*temp,*prev;
		//node* nn;
		//node* temp;
		
		//below int insert is also correct as it returns only integer
		void insert(int new_value){
			nn =new node();
			nn->data=new_value;
			nn->next=0;
			if(head==0){
				head=temp=nn;
			}
			else{
				temp->next=nn;
				//temp->data=new_value;
				temp=nn;
			}
		}
		
		void reverse(){
			node*curr,*nextnode;
			node* prev=0;
			curr=nextnode=head;
			while(nextnode!=0){
				nextnode=nextnode->next;      /*you can also excess next through curr*/
				curr->next=prev;
				prev=curr;  /*prev is basically maintained bcouz at last curr and next become zero so to accesss last element prev is there*/
				curr=nextnode;
			}
			head=prev;
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
	int k,j;
	cout<<"how many: ";
	cin>>j;
	for(int i=0;i<j;i++){
		cout<<"enter element: ";
		cin>>k;
		obj.insert(k);
	}
	obj.reverse();
	obj.display();
	return 0;
}
