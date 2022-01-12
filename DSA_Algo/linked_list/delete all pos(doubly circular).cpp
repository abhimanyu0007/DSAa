#include<iostream>
using namespace std;
struct node{
	int data;
	node* next;
	node* prev;
};
//once see video for if position is greater than length of list,etc
//above parameters are not included in this code.
//in below code observe use of delete_beg function in if statement 
class list{
	public:
		node* head=0,*nn,*tail,*temp;
		void insert(int new_value){
			nn=new node();
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
		
		void delete_beg(){
			temp=head;
			if(head==0){
				cout<<"list is empty";
			}
			else if(head->next==head){
				head=tail=0;
				free(temp);
			}
			else{
				head=head->next;
				head->prev=tail;
				tail->next=head;
				free(temp);
			}
		}
		
		void delete_end(){
			temp=tail;
			if(head==0){
				cout<<"list is empty";
			}
			else if(head->next==head){
				head=tail=0;
				free(temp);
			}
			else{
				tail=tail->prev;
				tail->next=head;
				head->prev=tail;
				free(temp);
			}
		}
		
		void delete_pos(int pos){
			temp=head;
			int i=1;
			if(head==0){
				cout<<"list is empty";
			}
			else if(pos==1){
				delete_beg();
			}
			else{
				while(i<pos){
					temp=temp->next;
					i++;
				}
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
				if(temp->next==head){
					tail=temp->prev;
					free(temp);
				}
				else{
					free(temp);
				}
			}
			
		}
		
		void display(){
			temp=head;
			do{
				cout<<temp->data<<" ";
				temp=temp->next;
			}while(temp!=head);
		}
		
		
};

int main(){
	list obj;
	int k,j,p;
	cout<<"how many: ";
	cin>>j;
	for(int i=0;i<j;i++){
		cout<<"enter element: ";
		cin>>k;
		obj.insert(k);
	}
	//obj.delete_beg();
	//obj.delete_end();
	cout<<"enter position for deletion of node: ";
	cin>>p;
	obj.delete_pos(p);
	obj.display();
	return 0;
}
