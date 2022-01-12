#include<iostream>
#define n 5

//perform other operatins like isempty,isfull

using namespace std;

class stack{
	public:
		int top=-1;
		int arr[100];
		
		void push(int value){
			if(top==n-1){
				cout<<"overflow";
			}
			else{
				top++;
				arr[top]=value;
			}
		}
		void pop(){
			int item;
			if(top==-1){
				cout<<"underflow";
			}
			else{
				//if don't want to know the popped element then simply put top-- only
				item=arr[top];
				top--;
			}
			cout<<"popped item is: "<<item;
		}
		
		void peek(){
			if(top==-1){
				cout<<"stack is empty";
			}
			else{
				cout<<"peek or top element is: "<<arr[top];
			}
		}
		
		void display(){
			cout<<endl;
			cout<<"elements are: ";
			for(int i=top;i>=0;i--){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
};



int main(){
	
	stack obj;
	int option,value;
	do{
		cout<<"enter operation you want to perform: "<<endl;
		cout<<"1. push()"<<endl;
		cout<<"2. pop()"<<endl;
		cout<<"3. peek()"<<endl;
		cout<<"4. display()"<<endl;
		cout<<"5. clear screen"<<endl;
		cout<<"press 0 to exit"<<endl;
		
		cin>>option;
		switch(option){
			case 0:
				break;
			case 1:
				cout<<"enter element to push: ";
				cin>>value;
				obj.push(value);
				break;
			case 2:
				obj.pop();
				break;
			case 3:
				obj.peek();
			case 4:
				obj.display();
				break;
			case 5:
				system("cls");
				break;
			default:
				cout<<"enter valid option"<<endl;
		}
	}while(option!=0);
	return 0;
}
