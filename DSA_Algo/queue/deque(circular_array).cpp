#include<iostream>
# define n 5
using namespace std;

int arr[n];
int f=-1,r=-1;

void enqueuefront(int x){
	//for other full cond. refer jenny lec. and to understand below condn. then solve it on page to see how it works.
	//after demonstrating it on page, then you'll on your own will form this cond.
	if((r+1)%n == f){
		cout<<"queue is full"<<endl;
	}
	//only r or f can also resolve below cond.
	else if(f==-1 && r==-1){
		f=r=0;
		arr[f]=x;
	}
	else if(f==0){
		f= n-1;
		arr[f]= x;
	}
	else{
		f--;
		arr[f]= x;
	}
}
void enqueuerear(int x){
	if((r+1)%n ==f){
		cout<<"queue is full"<<endl;
	}
	else if(f==-1 && r==-1){
		f=r=0;
		arr[r]=x;
	}
	else if(r== n-1){
		r=0;
		arr[r]=x;
	}
	else{
		r++;
		arr[r]=x;
	}
}
void display(){
	int i = f;
	cout<<"\n";
	if(f==-1 && r==-1){
		cout<<"queue is empty";
	}
	else{
		while(i!=r){
			cout<<arr[i]<<" ";
			i=(i+1)%n;
		}
		//why arr[r], to understand that, once use page and draw the flow of this algo to understand.
		cout<<arr[r];
	}
}
void getfront(){
	if(f==-1 && r==-1){
		cout<<"\nqueue is empty";
	}
	else{
		cout<<"\nfront element is: "<<arr[f];
	}
}
void getrear(){
	if(f==-1 && r==-1){
		cout<<"\nqueue is empty";
	}
	else{
		cout<<"\nrear element is: "<<arr[r];
	}
}
void dequeuefront(){
	if(f==-1 && r==-1){
		cout<<"\nqueue is empty";
	}
	else if(f==r){
		cout<<"\nfront dequeued element is: "<<arr[f];
		f=r=-1;
	}
	else if(f==n-1){
		cout<<"\nfront dequeued element is: "<<arr[f];
		f=0;
	}
	else{
		cout<<"\nfront dequeued element is: "<<arr[f];
		f++;
	}
}
void dequeuerear(){
	if(f==-1 && r==-1){
		cout<<"\nqueue is empty";
	}
	else if(f==r){
		cout<<"\nrear dequeued element is: "<<arr[r];
		f=r=-1;
	}
	else if(r==0){
		cout<<"\nrear dequeued element is: "<<arr[r];
		r=n-1;
	}
	else{
		cout<<"\nrear dequeued element is: "<<arr[r];
		r--;
	}
}

int main(){
	enqueuefront(1);
	enqueuefront(2);
	enqueuerear(3);
	enqueuerear(4);
	display();
	dequeuefront();
	dequeuerear();
	display();
	getfront();
	getrear();
	dequeuerear();
	dequeuerear();
	display();
	return 0;
}
