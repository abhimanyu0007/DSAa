#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[]){
	for(int i=0;i<4;i++){      //this loop will run for "size-1" times bcouz last element will be automatically replaced.
		int min = i;
		
		for(int j=i+1;j<5;j++){  //this will run for full size as we've to find min element throughout the array.
			if(arr[j] < arr[min]){  //this gives ascending order for descending change to "arr[j] > arr[min]
				min=j;
			}
		}
		
		if(min!=i){
			int temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}

int main(){
	int myarr[5];
	cout<<"Enter integers in random order: "<<endl;
	for(int i=0;i<5;i++){
		cin>>myarr[i];
	}
	cout<<"Unsorted array: ";
	for(int i=0;i<5;i++){
		cout<<myarr[i]<<" ";
	}
	cout<<endl;
	
	selectionSort(myarr);
	cout<<"Sorted array: ";
	for(int i=0;i<5;i++){
		cout<<myarr[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
