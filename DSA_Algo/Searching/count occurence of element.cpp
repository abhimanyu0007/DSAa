/*#include<iostream>
using namespace std;

int start(int arr[], int left, int right, int x){
	int ans= -1;
	while(left<=right){
		int mid= left + (right-left)/2;
		if(arr[mid]==x){
			ans=mid;
			right=mid-1;
		}
		else if(arr[mid]<x){
			left=mid+1;
		}
		else{
			right=mid-1;
		}
	}
	if(ans==-1) return -1;
	else return ans;
}

int end(int arr[], int left, int right, int x){
	int ans=-1;
	while(left<=right){
		int mid = left + (right-left)/2;
		if(arr[mid]==x){
			ans=mid;
			left=mid+1;
		}
		else if(arr[mid]<x){
			left=mid+1;
		}
		else{
			right=mid-1;
		}
	}
	if(ans==-1) return -2;
	else return ans;
}

int main(){
	
	int myarr[] = {0,0,0,1,1,1,2,2,2,3,4,4,4,4,4,6,6};
	int num = 4;
	int n = sizeof(myarr)/sizeof(myarr[0]);
	cout<<(end(myarr,0,n-1,num) - start(myarr,0,n-1,num))+1; 
	
	return 0;
}*/

/*#include<iostream>
using namespace std;

void calculate(int num){
	int sumEven, sumOdd, digit;
	while(num > 0){
		digit= num%10;
		num = num/10;
		
		if(digit%2==0){
			sumEven= sumEven+digit;
		}
		else{
			sumOdd= sumOdd*digit;
		}
	}
	cout<<sumEven<<" "<<sumOdd;
}

int main(){
	int num;
	cout<<"Enter six digit number: ";
	cin>>num;
	calculate(num);
	
	return 0;
}*/

#include<iostream>
using namespace std;

int main(){
	
	int r,c;
	cout<<"Enter no of rows and columns: ";
	cin>>r>>c;
	
	int mat[r][c];
	cout<<"Enter matrix elements: ";
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>mat[i][j];
		}
	}
	
	cout<<"Given Matrix"<<endl;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	
	for(int i=0;i<c;i++){
		int max= mat[0][i];
		for(int j=1;j<r;j++){
			if(mat[j][i] > max){
				max= mat[j][i];
			}
		}
		cout<<"largest element in col "<<i<<" : "<<max<<endl;
	}
	
	return 0;
}
