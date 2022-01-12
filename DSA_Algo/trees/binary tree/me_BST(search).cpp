#include<iostream>
#define SPACE 10  
using namespace std;

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
		BST(){
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
		
		void printPreorder(TreeNode* r){
			if(r==NULL){
				return;
			}
			cout<<r->value<<" ";
			printPreorder(r->left);
			printPreorder(r->right);
		}
		
		void printInorder(TreeNode* r){
			if(r==NULL){
				return;
			}                            //inorder traversal gives ascending order output
			printInorder(r->left);
			cout<<r->value<<" ";
			printInorder(r->right);
		}
		
		void printPostorder(TreeNode* r){
			if(r==NULL){
				return;
			}
			printPostorder(r->left);
			printPostorder(r->right);
			cout<<r->value<<" ";
		}
		/***********Iterative Search******/
		/*TreeNode* iterativeSearch(int v){
			if(root==NULL){
				return root;
			}
			else{
				TreeNode* temp=root;
				while(temp!=NULL){
					if(v == temp->value){
						return temp;
					}
					else if(v < temp->value){
						temp=temp->left;
					}
					else{
						temp=temp->right;
					}	
				}
				return NULL;
			}	
		}*/
		
		/***********Recursive Search**********/
		TreeNode* recursiveSearch(TreeNode *r, int val){
			if(r == NULL || r->value==val){
				return r;
			}
			else if(val < r->value) return recursiveSearch(r->left,val);
			else return recursiveSearch(r->right,val);
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
		cout<<"5. Clear Screen"<<endl;
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
				obj.insertNode(new_node);
				cout<<endl;
				break;
			case 2:
				cout<<"SEARCH"<<endl;
				cout<<"Enter value to search: ";
				cin>>val;
				//new_node creates memory in the heap, so to store heap data(temp data is in heap),
				//we initialize new memeory in heap using new_node
				//new_node = obj.iterativeSearch(val);  //new_node is used to deal with heap memory.
				new_node = obj.recursiveSearch(obj.root,val);
				
				if(new_node!=NULL){
					cout<<"Value found"<<endl;
				}
				else{
					cout<<"Value not found"<<endl;
				}
				break;
			case 3:
				cout<<"DELETE"<<endl;
				break;
			case 4:
				cout<<"PRINT and TRAVERSE"<<endl;
				obj.print2D(obj.root,5);  //visual way to print BST
				cout<<"Preorder traversal: ";
				obj.printPreorder(obj.root);
				cout<<endl;
				
				cout<<"Inorder traversal: ";
				obj.printInorder(obj.root);
				cout<<endl;
				
				cout<<"Postorder traversal: ";
				obj.printPostorder(obj.root);
				cout<<endl;
				break;
			case 5:
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
