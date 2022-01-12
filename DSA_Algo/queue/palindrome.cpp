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
		
		void palin(){
			//cout<<arr[front];
			//cout<<arr[rear];
			/*cout<<front<<endl;
			cout<<rear;*/
			int a=0;
			while(front != 2){
				if(arr[front] == arr[rear]){
					//return "\nnot palindrome";
					a=1;
					front++;
					rear--;	
				}
				else{
					cout<<"\nnot";
					break;
				}
			}
			if(a==1){
				cout<<"\n yes palin";
			}	
		}
		
		
};

int main(){
	queue obj;
	obj.enqueue(1);
	obj.enqueue(2);
	obj.enqueue(3);
	obj.enqueue(2);
	obj.enqueue(1);
	obj.palin();
	return 0;
}
