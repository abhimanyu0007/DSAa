#include<iostream>
using namespace std;

struct node{
	int data;
	node* next;
};

class list{
	public:
		node* head,*temp,*nn;
		void insert(int value){
			nn=new node();
			nn->data=value;
			nn->next=NULL;
			
			if(head==NULL){
				head=temp=nn;
			}
			else{
				temp->next=nn;
				temp=nn;
			}
		}
		
		void delete_beg(){
			if(head==NULL){
				cout<<"list is empty";
			}
			else{
				temp=head;
				head=head->next;
				free(temp);
				
			}
		}
		
		void delete_end(){
			node* prev;
			if(head==NULL){
				cout<<"list is empty";
			}
			else{
				temp=head;
				while(temp->next!=NULL){
					prev=temp;
					temp=temp->next;
				}
				prev->next=NULL;
				free(temp);
			}
		}
		
		void delete_pos(int pos){
			if(pos==1){
				if(head==NULL){
				cout<<"list is empty";
				}
				else{
					temp=head;
					head=head->next;
					free(temp);
					
				}
			}
			else{
			
			node* nextnode;
			int z=1;
			temp=head;
			while(z<pos-1){
				temp=temp->next;
				z++;
			}
			nextnode=temp->next;
			temp->next=nextnode->next;
			free(nextnode);
			}
			
		}
		
		void display(){
			temp=head;
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
		}
};
int main(){
	list obj;
	int n,e,p;
	cout<<"enter no of elements: ";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"enter element: ";
		cin>>e;
		obj.insert(e);
	}
	cout<<"before deletion"<<endl;
	//in hackerrank be aware of below display as it prints two displays then it may lead to error
	obj.display();
	cout<<"\nenter position: ";
	cin>>p;
	obj.delete_pos(p);
	cout<<"\nafter deletion"<<endl;
	obj.display();
	return 0;
	
	
}
