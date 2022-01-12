#include<iostream>
# define n 5
using namespace std;

class queue{
	public:
		int arr[n];
		int front=-1,rear=-1;
		
		/*here (rear/front+1)%n is used bcouz it is in circular flow, after last element it should go to first element, once check flow
		to understand in better way*/ 
		
		void enqueue(int x){
			if(front==-1 && rear==-1){
				front=rear=0;
				arr[rear]=x;
			}
			else if((rear+1)%n == front){
				cout<<"queue is full";
			}
			else{
				rear=(rear+1)%n;
				arr[rear]=x;
			}
		}
		
		void dequeue(){
			if(front==-1 && rear==-1){
				cout<<"\nqueue is empty";
			}
			else if(front==rear){
				/*it means queue is empty, then according to empty queue condition front and rear =-1
				bcouz at starting when queue is empty front and rear =-1*/
				front=rear= -1;
			}
			else{
				cout<<"dequeued element is: "<<arr[front]<<endl;
				front=(front+1)%n;
			}
		}
		
		void peek(){
			if(front==-1 && rear==-1){
				cout<<"\nqueue is empty";
			}
			else{
				cout<<"\npeek element is: "<<arr[front]<<endl;
			}
		}
		
		void display(){
			/*if confused then once check jenny video*/
			int i=front;
			if(front==-1 && rear==-1){
				cout<<"queue is empty";
			}
			else{
				while(i!=rear){
					cout<<arr[i]<<" ";
					i=(i+1)%n;
				}
			}
			cout<<arr[rear];
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
	obj.display();
	obj.peek();
	obj.enqueue(6);
	obj.display();
	return 0;
}

