#include<iostream>
using namespace std;

int top=-1;
int arr[100];
int n=100;
		
void push(int value){
	if(top==n-1){
		cout<<"overflow";
	}
	else{
		top++;
		arr[top]=value;
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
int main(){
	push(1);
	push(2);
	display();
	return 0;
}
