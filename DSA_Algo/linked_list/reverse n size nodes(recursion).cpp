#include<iostream>
using namespace std;

struct node{
	int data;
	node* next;
	
	node(int x){
		data=x;
		next=0;
	}
};

class list{
	public:
		node* reverse(node* head,int k){
			node* prev,*curr,*nextn;
			prev=0;
			nextn=curr=head;
			int c=0;
			while(curr!=0 && c<k){
				nextn=curr->next;      /*you can also excess next through curr*/
				curr->next=prev;
				prev=curr;  /*prev is basically maintained bcouz at last curr and next become zero so to accesss last element prev is there*/
				curr=nextn;
				c++;
			}
			if(nextn!=0){
				head->next=reverse(nextn,k);
			}
			head=prev;
			return prev;
	
		}
		
		
		void display(node* head){
			while(head!=0){
				cout<<head->data<<" ";
				head=head->next;
			}
		}
};

int main(){
	/*list obj;
	int k,j,l;
	node* head=0;
	cout<<"how many: ";
	cin>>j;
	for(int i=0;i<j;i++){
		cout<<"enter element: ";
		cin>>k;
		head=obj.insert(head,k);
	}
	l=3;
	obj.reverse(head,l);
	obj.display(head);*/
	node* head=0;
	node* temp=0;
	int n;
	cout<<"how many: ";
	cin>>n;
	for(int i=0;i<n;i++){
		int value;
		cout<<"\nenter value: ";
		cin>>value;
		if(i==0){
			head=new node(value);
			temp=head;
		}
		else{
			temp->next=new node(value);
			temp=temp->next;
		}
	}
	int k;
	k=3;
	list obj;
	/*for(int i=0;i<n;i++){
		head=obj.reverse(head,k);
	}*/
	head=obj.reverse(head,k);
	obj.display(head);
	return 0;
}
