#include<bits/stdc++.h>
using namespace std;

void swap(int &x, int &y){
	int temp=x;
	x=y;
	y=temp;
}

void bubbleSort(int arr[]){
	int n=5;  //size of array 
	for(int i=0; i<n; i++){
		for(int j=0; j<n-i-1;j++){
			if(arr[j] > arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
		}
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
	
	bubbleSort(myarr);
	cout<<"Sorted array: ";  //you can even write "cout<<endl<<"sorted array;"
	for(int i=0;i<5;i++){
		cout<<myarr[i]<<" ";
	}
	
	return 0;
}
