#include<iostream>
using namespace std;
int main(){
	int t;
	cout<<"enter t:";
	cin>>t;
	int arr[t][6];
	for(int i=0;i<t;i++){
		cin>>arr[i][0]>>arr[i][1]>>arr[i][2]>>arr[i][3]>>arr[i][4]>>arr[i][5];
	}
	for(int i=0;i<t;i++){
		int c=0;
		if((arr[i][0] ==arr[i][2]) && arr[i][1]==arr[i][3]){
			cout<<1<<endl;
			c=1;
			
		}
		if((arr[i][0] ==arr[i][3]) && arr[i][1]==arr[i][2]){
			cout<<1<<endl;
			c=1;
			
		}
		
		if((arr[i][0] ==arr[i][4]) && arr[i][1]==arr[i][5]){
			cout<<2<<endl;
			c=1;
			
		}
		if((arr[i][0] ==arr[i][5]) && arr[i][1]==arr[i][4]){
			cout<<2<<endl;
			c=1;
			
		}
		if(c==0){
			cout<<0<<endl;
		}
	}
	return 0;
}
