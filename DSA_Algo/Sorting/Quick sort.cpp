#include<bits/stdc++.h>
using namespace std;

void swap(int &x, int &y){
	int temp=x;
	x=y;
	y=temp;
}

int partition(int arr[],int s,int e){  //space complexity is logn, logn is of recursive call which is auxillary memory required at runtime.
	int pivot= arr[e];
	int pindex= s;
	for(int i=s;i<e;i++){
		if(arr[i]<pivot){
			swap(arr[i], arr[pindex]);
			pindex++;
		}
	}
	swap(arr[e], arr[pindex]);
	return pindex;
}

void quickSort(int arr[],int s,int e){
	if(s<e){
		int p= partition(arr,s,e);
		quickSort(arr,s,p-1);
		quickSort(arr,p+1,e);
	}
}

int main(){
	int size;
	cout<<"Enter size of array: ";
	cin>>size;
	int myarr[size];
	cout<<"Enter "<<size<<" elements in array: ";
	for(int i=0;i<size;i++){
		cin>>myarr[i];
	}
	
	cout<<"Before Quick sort: ";
	for(int i=0;i<size;i++){
		cout<<myarr[i]<<" ";
	}
	cout<<endl;
	
	quickSort(myarr,0,size-1);
	
	cout<<"After Quick sort: ";
	for(int i=0;i<size;i++){
		cout<<myarr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
