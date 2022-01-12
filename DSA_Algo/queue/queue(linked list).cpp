#include<iostream>
using namespace std;
struct node{
	int data;
	node* next;
};
class queue{
	public:
		node* front=0,*rear=0,*nn,*temp;
		void enqueue(int x){
			nn=new node();
			nn->data=x;
			nn->next=0;
			if(front==0 && rear==0){
				front=rear=nn;
			}
			else{
				rear->next=nn;
				rear=nn;
			}
		}
		
		void dequeue(){
			temp=front;
			if(front==0 && rear==0){
				cout<<"it is empty";
			}
			else{
				cout<<"dequeued element is: "<<front->data<<endl;
				front=front->next;
				free(temp);
			}
		}
		
		void peek(){
			if(front==0 && rear==0){
				cout<<"it is empty";
			}
			else{
				cout<<"peek element is: "<<front->data<<endl;
			}
		}
		
		void display(){
			if(front==0 && rear==0){
				cout<<"it is empty";
			}
			else{
				temp=front;
				while(temp!=0){
					cout<<temp->data<<" ";
					temp=temp->next;
				}
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
	
	obj.dequeue();
	obj.peek();
	obj.display();
	return 0;
}
