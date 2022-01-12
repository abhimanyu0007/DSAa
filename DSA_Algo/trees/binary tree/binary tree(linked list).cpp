#include<iostream>
using namespace std;

struct node{
	int data;
	node* left, *right;
};
//as it is going to return pointer so,
node* create(){
	int x;
	node *nn;
	nn = new node();
	cout<<"enter element: or to exit enter -1 ";
	cin>>x;
	if(x==-1){
		return 0;
	}
	nn->data=x;
	cout<<"enter left child of ",x,": ";
	nn->left=create();
	cout<<"enter right child of ",x,": ";
	nn->right=create();
	return nn;
}

int main(){
	node* root;
	root =0;
	root= create();
	return 0;
}

