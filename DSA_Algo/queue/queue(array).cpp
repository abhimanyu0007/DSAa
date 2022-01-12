#include<iostream>
#define n 5
using namespace std;

class queue{
	public:
		int arr[5];
		int front=-1;
		int rear =-1;
		
		void enqueue(int value){
			if(rear==n-1){
				cout<<"Overflow Condition(it is full)"<<endl;
			}
			else if(front==-1 && rear==-1){
				front=rear=0;
				arr[rear]=value;
			}
			else{
				rear++;
				arr[rear]=value;
			}
		}
		
		void dequeue(){
			if(front==-1 && rear==-1){
				cout<<"Underflow Condition(it is empty)"<<endl;
			}
			else if(front==rear){
				/*it means queue is empty, then according to empty queue condition front and rear =-1
				bcouz at starting when queue is empty front and rear =-1*/
				front=rear=-1;
			}
			else{
				cout<<"dequeued elements is: "<<arr[front]<<endl;
				front++;
			}
		}
		
		void peek(){
			if(front==-1 && rear==-1){
				cout<<"Underflow Condition(it is empty)"<<endl;
			}
			else{
				cout<<"peek element is: "<<arr[front]<<endl;
			}
		}
		
		void display(){
			if(front==-1 && rear==-1){
				cout<<"Underflow Condition(it is empty)"<<endl;
			}
			else{
				for(int i=front;i<=rear;i++){
					cout<<arr[i]<<" ";
				}
			}
		}
};

int main(){
	queue obj;
	obj.enqueue(0);
	obj.enqueue(2);
	obj.enqueue(3);
	obj.enqueue(4);
	obj.enqueue(5);
	obj.dequeue();
	obj.peek();
	obj.display();
	return 0;
}
