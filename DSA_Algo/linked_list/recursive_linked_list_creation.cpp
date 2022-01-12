
#include<iostream>
using namespace std;

struct node{
	int data;
	node* next;
};

class list{
	public:
		//node* nn;
		//node* temp;
		
		//below int insert is also correct as it returns only integer
		node *new_node(int data){
			node* nn=new node;
			nn->data=data;
			nn->next=0;
			return nn;
		}
		
		//when there is return of pointer(return type is pointer), then func name should relate to pointer(node* func_name)
		// datatype before variable is for declaration, refer below line
		node* insert(node* head,int data){
			if(head==0){
				return new_node(data);
			}
			else{
				head->next=insert(head->next,data);
			}
			return head;
		}
		
	
		//node* reverse()
		
		
		void display(node* head){
			if(head==0){
				return;
			}
			cout<<head->data<<" ";
			display(head->next);
		}
};

int main(){
	list obj;
	int k,j;
	node* shead=0;
	cout<<"how many: ";
	cin>>j;
	for(int i=0;i<j;i++){
		cout<<"enter element: ";
		cin>>k;
		//shead variable is declared to store the return value head of insert function like we used temp variable for traversal.
		/*  if input is 1 2 3 4
			consider i=0 shead gets return value 1
		   			 i=i shead stores return value 2
		   	which means shead gets repeatdly used for new values
		   	eg.:shead=insert(shead,1)
		   		shead=insert(shead,2)
		   		shead=insert(shead,3)
		   		shead=insert(shead,4)
		*/ 
		shead=obj.insert(shead,k);
	}
	//obj.reverse();
	obj.display(shead);
	return 0;
}
