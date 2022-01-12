#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[]){
	for(int i=1;i<5;i++){
		int key= arr[i];
		int j= i-1;
		while(j>=0 && arr[j] > key){
			arr[j+1] = arr[j];
			j=j-1;
		}
		arr[j+1] =key;
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
	
	insertionSort(myarr);
	cout<<"Sorted array: ";
	for(int i=0;i<5;i++){
		cout<<myarr[i]<<" ";
	}
	cout<<endl;
}
