#include<iostream>
using namespace std;
int main(){
	int t,x,y,z;
	cout<<"testcases: ";
	cin>>t;
	int arr[t][3];
	for(int i=0;i<t;i++){
		cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
		
	}
	for(int i=0;i<t;i++){
		if(arr[i][0]==arr[i][1] &&arr[i][1]==arr[i][2]){
			cout<<0<<endl;
		}else{
			cout<<1<<endl;
		}
	}
	return 0;
}
