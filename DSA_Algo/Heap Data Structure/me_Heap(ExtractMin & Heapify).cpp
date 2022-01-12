#include<bits/stdc++.h>
using namespace std;

void swap(int &x, int &y){  //you can even keep this func inside class
	int temp=x;   //you can even do swapping using pointers
	x=y;
	y=temp;
}

class MinHeap{
	//below data members harr,capacity and heap_size can be kept in private access specifier.
	//bcouz usually data members are kept in private
	public:
		int *harr;   //pointer to array of elements in heap
		int capacity;  //maximum possible size of min heap
		int heap_size; //current number of elements in min heap
		
		MinHeap(int cap){
			heap_size = 0;
			capacity = cap;
			harr = new int[cap];
		}
		
		void linearSearch(int val){
			for(int i=0;i<heap_size;i++){  //refer pink colour tree node structure SS in heap data structure to 
				if(harr[i] == val){        //get idea about heap_size and capacity
					cout<<"Value Found";
					return;
				}
			}
			cout<<"Value not found";
		}
		
		void printArray(){
			for(int i=0;i<heap_size;i++){
				cout<<harr[i]<<" ";
			}
			cout<<endl;
		}
		
		int height(){
			return ceil(log2(heap_size + 1)) - 1;
		}
		
		int parent(int i){
			return (i-1)/2;
		}
		
		int left(int i){
			return (2*i + 1);
		}
		
		int right(int i){
			return (2*i + 2);
		}
		
		void insertKey(int k){
			if(heap_size == capacity){
				cout<<"\nOverflow: Could not insert Key\n";
				return;
			}
			
			//insert key at the end
			heap_size++;
			int i = heap_size - 1;
			harr[i] = k;
			
			//check whether new value is minimum or not
			while(i!=0 && harr[parent(i)] > harr[i]){
				swap(harr[i], harr[parent(i)]);
				i=parent(i);
			}
			/*else{
				heap_size++;
				int i = heap_size - 1;
				harr[i] = k;
				while(i!=0 && harr[parent(i)] > harr[i]){
					swap(harr[i], harr[parent(i)]);
					i=parent(i);
				}
			}*/	
		}
		
		void MinHeapify(int i){
			int l= left(i);
			int r= right(i);
			int smallest = i; //below line heap_size condition is used bcouz earlier we did heap_size-- which means we had deleted one element
							  //that element will be present, but it will be of no use, so maintain that cond we use heap_size cond.
			if(l < heap_size && harr[l] < harr[i]) 
				smallest = l;
			if(r < heap_size && harr[r] < harr[smallest])
				smallest = r;
			if(smallest!= i){
				swap(harr[i], harr[smallest]);
				MinHeapify(smallest);
			} 
		}
		
		int extractMin(){
			if(heap_size <= 0) return INT_MAX; //if heap_size gets 0 or below 0 then program will throw O/P=> INT_MAX. Eg. if u inserted 2 values and extracted
			if(heap_size == 1){                 //that both values, then heap_size will be null, then tell that we can use if, else cond that heap size is 0.
				heap_size--;
				return harr[0];
			}
			
			//store the minimum value and remove it from loop
			int root= harr[0];
			harr[0]= harr[heap_size-1];
			heap_size--;
			MinHeapify(0); //this is recursive step, analyze it carefully
			return root; 
		}
};

int main(){
	int s;
	cout<<"enter the size of Min Heap"<<endl;
	cin>>s;
	MinHeap obj(s);
	cout<<"Min Heap Created"<<endl;
	
	int option,val;
	do{
		cout<<"What operation to you want to perform? "
		<<"Select Option number. Enter 0 to exit."<<endl;
		
		cout<<"1. Insert key/Node/value"<<endl;
		cout<<"2. Search key/Node"<<endl;
		cout<<"3. Delete key/Node"<<endl;
		cout<<"4. Get Min"<<endl;
		cout<<"5. Extract Min"<<endl;
		cout<<"6. Height of Heap"<<endl;
		cout<<"7. Print/Traversal Heap values"<<endl;
		cout<<"8. Clear Screen"<<endl;
		cout<<"0. Exit Program"<<endl;
	
		cin>>option;
		
		switch(option){
			case 0:
				break;
			case 1:
				cout<<"INSERT Operation -"<<endl;
				cout<<"Enter Value to insert in Heap: ";
				cin>>val;
				obj.insertKey(val);
				cout<<endl;
				break;
			case 2:
				cout<<"SEARCH Operation -"<<endl;
				cout<<"Enter Value to Search: ";
				cin>>val;
				//obj.linearSearch(val);
				break;
			case 3:
				cout<<"DELETE Operation -"<<endl;
				cout<<"Enter inder of Heap array to DELETE: ";
				cin>>val;
				//obj.deleteKey(val);
				break;
			case 4:
				cout<<"Get Min value: ";
				//cout<<obj.getMin()<<endl;
				cout<<endl;
				break;
			case 5:
				cout<<"Extract Min value: ";
				cout<<obj.extractMin()<<endl;
				cout<<endl;
				break;
			case 6:
				cout<<"HEAP TREE HEIGHT: ";
				//cout<<obj.height()<<endl;
				break;
			case 7:
				cout<<"PRINT HEAP ARRAY: "<<endl;
				obj.printArray();
				cout<<endl;
				break;
			case 8:
				system("cls");
				break;
			default:
				cout<<"Enter proper option number "<<endl;
		}
		
	}while(option!=0);
	return 0;
}
