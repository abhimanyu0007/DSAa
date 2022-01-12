#include<bits/stdc++.h>
/*#include<iostream>
#include<vector>
#include<queue>*/
#define SPACE 10  
using namespace std;

//if only return is there, then it is bcouz of recursion and for others like iterative we need to return something

class TreeNode{
	public:
		int value;    //value also known as key or data
		TreeNode* left;
		TreeNode* right;
		
		TreeNode(){
			value=0;
			left=NULL;
			right=NULL;
		}
		
		TreeNode(int v){
			value=v;
			left=NULL;
			right=NULL;
		}
};
//if code is not understandable, then once refer simplesnippets youtube video pseudocode.
class BST{
	public:
		TreeNode* root;
		BST(){  //check for all code there no need of constructor
			root=NULL;
		}
		
		bool isEmpty(){
			if(root==NULL){
				return true;
			}
			else{
				return false;
			}
		}
		
		void insertNode(TreeNode *new_node){
			if(root==NULL){
				root=new_node;
				cout<<"Value Inserted as root node"<<endl;
			}
			else{
				TreeNode *temp=root;
				while(temp!=NULL){
					if(new_node->value == temp->value){
						cout<<"Value already exist, insert another value";
						return;
					}
					else if((new_node->value < temp->value) && (temp->left==NULL)){
						temp->left=new_node;
						cout<<"Value Inserted to the left"<<endl;
						break;
					}
					else if(new_node->value < temp->value){
						temp=temp->left;
					}
					else if((new_node->value > temp->value) && (temp->right==NULL)){
						temp->right=new_node;
						cout<<"Value Inserted to the right"<<endl;
						break;
					}
					else{
						temp=temp->right;
					}
				}
			}
		}
		
		TreeNode* insertRecursive(TreeNode* r, TreeNode* new_node){
			if(r==NULL){
				r = new_node;
				return r;
			}
			if(new_node->value < r->value){
				r->left = insertRecursive(r->left, new_node);
			}
			else if(new_node->value > r->value){
				r->right = insertRecursive(r->right, new_node);
			}
			else{
				cout<<"No duplicate value allowed!"<<endl;
				return r;
			}
			return r;
		}
		
		void print2D(TreeNode *r, int space){
			if(r==NULL){
				return;
			}
			space +=SPACE;
			print2D(r->right, space);
			cout<<endl;
			for(int i=SPACE;i<space;i++){
				cout<<" ";
			}
			cout<<r->value<<"\n";
			print2D(r->left, space);
		}
		
		                           
		int height(TreeNode* r){ 
			int lheight,rheight;
			if(r==NULL){
				return -1;  //return 0 for +1 resultant height value
			}
			lheight = height(r->left);
			rheight = height(r->right);
			return(1 + max(lheight,rheight));
		}
		
		/**left view of tree**/
		void printGivenLevel(TreeNode* r){
			if(root == NULL) return ;
			queue<TreeNode*>q;
			q.push(root);
			while(!q.empty()){
				int n = q.size();
				for(int i =1;i<=n;i++){
					TreeNode *temp = q.front();
					q.pop();
					if(i==1){
						cout<<temp->value<<" ";
					}
					if(temp->left != NULL) q.push(temp->left); 
					if(temp->right != NULL) q.push(temp->right);
				}
			}
		}
		
		
		
	
};

int main(){
	BST obj;
	int option,val;
	
	do{
		cout<<"What operation do you want to perform? "
		<<"Select Option number. Enter -1 to exit."<<endl;
		cout<<"1. Insert Node"<<endl;
		cout<<"2. Search Node"<<endl;
		cout<<"3. Delete Node"<<endl;
		cout<<"4. Print BST values"<<endl;
		cout<<"5. Print level order BFS"<<endl;
		cout<<"6. Height of Tree"<<endl;
		cout<<"7. Clear Screen"<<endl;
		cout<<"-1. Exit Program"<<endl;
		
		cin>>option;
		TreeNode *new_node = new TreeNode();
		
		switch(option){
			case -1:
				break;
			case 1:
				cout<<"INSERT"<<endl;
				cout<<"Enter value of TreeNode to insert in BST: ";
				cin>>val;
				new_node->value = val;
				//obj.insertNode(new_node);   //this line is for iterative insertion
				obj.root = obj.insertRecursive(obj.root , new_node);
				cout<<endl;
				break;
			
			case 5:
				cout<<"Level order BFS: ";
				obj.printGivenLevel(obj.root);
				cout<<endl;
				break;
		
			case 7:
				//cout<<"CLEAR SCREEN"<<endl;  no need to type this line, bcouz this will also get cleared.
				system("cls");
				break;
			default:
				cout<<"Enter proper option number "<<endl;
		}
	}
	while(option!=0);	
	
	return 0;
}
