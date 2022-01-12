#include<bits/stdc++.h>
using namespace std;

void swap(int &x, int &y){
	int temp = x;
	x=y;
	y=temp;
}

void optimizedBubbleSort(int arr[]){
	int n=5;
	for(int i=0;i<n;i++){
		bool flag = false;  //if array is already sorted then there is no need to go further, so it reduces num of rounds in the code.
		for(int j=0;j<n-i-1;j++){
			if(arr[j] > arr[j+1]){
				flag = true;
				swap(arr[j], arr[j+1]);
			}
		}
		if(flag==false) break;
	}
}

int main(){
	int myarr[5];
	cout<<"Enter integers in random order: ";
	for(int i=0;i<5;i++){
		cin>>myarr[i];
	}
	cout<<"Unsorted array: ";
	for(int i=0;i<5;i++){
		cout<<myarr[i]<<" ";
	}
	cout<<endl;
	
	optimizedBubbleSort(myarr);
	cout<<"Sorted array: ";  //you can even write "cout<<endl<<"sorted array;"
	for(int i=0;i<5;i++){
		cout<<myarr[i]<<" ";
	}
	
	return 0;
}
