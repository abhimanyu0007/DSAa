#include<iostream>
using namespace std;

struct node{
	int data;
	node* next;
};

class queue{
	public:
		node* front=0,*rear=0,*nn;
		void enqueue(int x){
			nn=new node();
			nn->data= x;
			nn->next= 0;
			
			if(front==0 && rear==0){
				front=rear=nn;
				rear->next=front;
			}
			else{
				rear->next=nn;
				rear=nn;
				rear->next=front;
			}
		}
		
		void dequeue(){
			node* temp;
			temp= front;
			
			//if(front==0) or rear==0 is also right, check other conditions too.
			if(front==0 && rear==0){
				cout<<"queue is empty"<<endl;
			}
			else if(front == rear){
				cout<<"dequeued element is: "<<front->data<<endl;
				front=rear=0;
				free(temp);
			}
			else{
				cout<<"dequeued element is: "<<front->data<<endl;
				front= front->next;
				rear->next=front;
				free(temp);
			}
		}
		
		void peek(){
			if(front==0 && rear==0){
				cout<<"queue is empty"<<endl;
			}
			else{
				cout<<"peek elememt is: "<<front->data<<endl;
			}
		}
		
		void display(){
			node* temp;
			temp=front;
			if(front==0 && rear==0){
				cout<<"queue is empty"<<endl;
			}
			else{
				while(temp->next!=front){
					cout<<temp->data<<" ";
					temp=temp->next;
				}
				cout<<temp->data<<endl;
			}
		} 
};

int main(){
	queue obj;
	obj.enqueue(1);
	obj.enqueue(2);
	obj.enqueue(3);
	obj.enqueue(4);
	obj.enqueue(5);
	obj.display();
	obj.peek();
	obj.dequeue();
	obj.peek();
	obj.display();
	return 0;
}
