#include<iostream>
/*you can also use scope resolution to define functions outside class
*link is like prev*/
using namespace std;

struct node{
	int data;
	node* link;
};

class stack{
	public:
		node* top=0,*nn,*temp;
		
		void push(int value){
			nn =new node();
			nn->data=value;
			nn->link=top;
			top=nn;
		}
		
		void pop(){
			temp=top;
			if(top==0){
			cout<<"stack is empty"<<endl;
			}
			else{
				cout<<"popped element is: "<<top->data<<endl;
				top=top->link;
				free(temp);
			}
		}
		
		void peek(){
			if(top==0){
				cout<<"stack is empty";
			}
			else{
				cout<<"peek element is: "<<top->data<<endl;
			}
		}
		
		void display(){
			temp=top;
			if(top==0){
				cout<<"stack is empty"<<endl;
			}
			else{
				while(temp!=0){
					cout<<temp->data<<" ";
					temp=temp->link;
				}
				cout<<endl;
			}
		}
};

int main(){
	//refer stack using array to use switch cases
	
	stack obj;
	obj.push(1);
	obj.push(2);
	obj.push(3);
	obj.push(4);
	cout<<"stack created: ";
	obj.display();
	
	obj.pop();
	obj.peek();
	obj.display();
	return 0;
}
