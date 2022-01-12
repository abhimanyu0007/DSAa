#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int left,int right,int x){
	while(left<=right){
		int mid = left + (right-left)/2; //we didn't use left+right/2 bcouz it gives error for larger integers, refer SS in binary search folder.
		if(arr[mid]==x) return mid;
		else if(arr[mid]<x) left=mid + 1;
		else right=mid -1 ;
		
		//below is simplified code with brackets for better understanding
		/*if(arr[mid]==x){
			return mid;
		}
		else if(arr[mid]<x){
			left=mid + 1;
		}
		else{
			right=mid -1;
		}*/
	}
	return -1;
}

int main(){
	int num;
	int myarr[10];
	int output;
	
	cout<<"Enter 10 integers in ASCENDING order: "<<endl;
	for(int i=0;i<10;i++){
		cin>>myarr[i];
	}
	
	cout<<"Enter number to search: "<<endl;
	cin>>num;
	
	output=binarySearch(myarr,0,9,num);
	
	if(output==-1) cout<<"No match found"<<endl;
	else cout<<"Match found at Index: "<<output<<endl;
	return 0;
}
