
/*#include<iostream>
using namespace std;
struct node{
	int prn;
	node *next;
};
int main(){
	node *head;
	node *one=NULL;
	node *two=NULL;
	
	one=new node();
	two=new node();
	
	one->prn=1;
	two->prn=2;
	
	one->next=two;
	two->next=NULL;
	
	head=one;
	while(head!=NULL){
		cout<<head->prn<<"---->";
		head=head->next;
	}
	if(head==NULL)
	cout<<"null";
}*/
                           
#include<iostream>
using namespace std;
struct node{
	int value;
	node* next;
};
class number{
	public:
		node* header;
		node* nn;
		void insert(int new_value){
			nn=new node();
		
			nn->value=new_value;
			nn->next=header;
			header=nn;
			
				
		}	
		void display(){
			node* ptr;
			ptr=header;
			while(ptr!=NULL){
				cout<<ptr->value<<" ";
				ptr=ptr->next;
			}
		}
};

int main(){
	number obj;
	int k,j,h;
	cout<<"how many: ";
	cin>>j;
	for(int i=1;i<=j;i++){
		cout<<"enter element: ";
		cin>>k;
		obj.insert(k);
	}
	obj.display();
	return 0;
}





