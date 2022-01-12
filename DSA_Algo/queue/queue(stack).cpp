#include<iostream>
# define n 5
using namespace std;

class queue{
	public:
		//we need 2 stacks for implementing queue as stack
		int s1[n], s2[n];
		int top1= -1, top2= -1;
		int count =0;
		//you can also solve this using empty func instead of using count, refer geeks for geeks
		/*refer photo of that question solution, bcouz in gfg website,at second soln there is one error at last
		see in photo steps after comment of retun num are solution of that error, solve on page to get clear idea*/
		void push1(int data){
			if(top1==n-1){
				cout<<"queue is full"<<endl;
			}
			else{
				top1++;
				s1[top1]=data;
			}
		}
		void push2(int data){
			if(top2==n-1){
				cout<<"queue is full"<<endl;
			}
			else{
				top2++;
				s2[top2]=data;
			}
		}
		int pop1(){
			return s1[top1--];
		}
		int pop2(){
			return s2[top2--];
		}
		
		void enqueue(int x){
			push1(x);
			count++;
		}
		void dequue(){
			int a,b;
			if(top1==-1 &&top2==-1){
				cout<<"queue is empty"<<endl;
			}
			else{
				for(int i=0;i<count;i++){
					a=pop1();
					push2(a);
				}
				b=pop2();
				cout<<"\ndequeued element is: "<<b<<endl;
				count--;
				for(int i=0;i<count;i++){
					a=pop2();
					push1(a);
				}
			}
		}
		
		void display(){
			if(top1==-1 && top2==-1){
				cout<<"Underflow Condition(it is empty)"<<endl;
			}
			else{
				for(int i=0;i<count;i++){
					cout<<s1[i]<<" ";
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
	obj.display();
	obj.dequue();
	obj.display();
}
