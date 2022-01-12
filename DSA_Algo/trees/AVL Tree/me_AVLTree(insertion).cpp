#include<iostream>
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
class AVLTree{
	public:
		TreeNode* root;
		AVLTree(){  //check for all code there no need of constructor
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
		
		int getBalanceFactor(TreeNode *n){
			if(n==NULL) return -1;
			return height(n->left) - height(n->right);
		}
		
		TreeNode *rightRotate(TreeNode *y){   //once refer SS in AVL tree folder
			TreeNode *x = y->left;
			TreeNode *T2= x->right;
			//Perform rotation
			x->right = y;
			y->left = T2;
			return x;
		}
		
		TreeNode *leftRotate(TreeNode *x){
			TreeNode *y = x->right;
			TreeNode *T2 = y->left;
			//Perform rotation
			y->left = x;
			x->right = T2;
			return y;
		}
		
		TreeNode* insertRecursive(TreeNode *r, TreeNode *new_node){
			if(r == NULL){
				r = new_node;
				cout<<"Value inserted"<<endl;
				return r;
			}
			if(new_node->value < r->value){
				r->left = insertRecursive(r->left, new_node);
			}
			else if(new_node->value > r->value){
				r->right = insertRecursive(r->right, new_node);
			}
			else{
				cout<<"No duplicate values allowed"<<endl;
				return r;
			}
			
			int bf = getBalanceFactor(r);
			//for below code don't use if,else if,else conditions bcuoz if we use it then we won't be able to send condition  for last else statement
			//so define 4 conditions use only if statement or use if, else if conditions only not else condition. 
			
			//Left Left Case
			if(bf>1 && new_node->value < r->left->value) return rightRotate(r);
			
			//Right Right Case
			if(bf<-1 && new_node->value > r->right->value) return leftRotate(r);
			
			//Left Right Case
			if(bf>1 && new_node->value > r->left->value){
				r->left = leftRotate(r->left);
				return rightRotate(r);
			}
			
			//Right Left Case
			if(bf<-1 && new_node->value < r->right->value){
				r->right = rightRotate(r->right);
				return leftRotate(r);
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
		
		TreeNode* iterativeSearch(int v){
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
		}
		
		/***********Recursive Search**********/
		TreeNode* recursiveSearch(TreeNode *r, int val){
			if(r == NULL || r->value==val){
				return r;
			}
			else if(val < r->value) return recursiveSearch(r->left,val);
			else return recursiveSearch(r->right,val);
		}
		
		/*int height(TreeNode* r){
			int lheight,rheight;
			if(r==NULL){     
				return -1;
			}
			else{
				lheight = height(r->left);
				rheight = height(r->right);
			}
			if(lheight > rheight){
				return(lheight + 1);
			}
			else{
				return(rheight + 1);
			}
		}*/
		
		/******************or for height****************/
		int height(TreeNode* r){ 
			int lheight,rheight;
			if(r==NULL){
				return -1;  //return 0 for +1 resultant height value
			}
			lheight = height(r->left);
			rheight = height(r->right);
			return(1 + max(lheight,rheight));
		}
		
		/**below function(printGivenLevel) print nodes at a given level**/
		void printGivenLevel(TreeNode* r, int level){
			if(r==NULL){
				return;
			}
			else if(level==0){
				cout<<r->value<<" ";
			}
			else{  //level>0
				printGivenLevel(r->left, level-1);
				printGivenLevel(r->right, level-1);
			}
		}
		void printLevelOrderBFS(TreeNode* r){
			int h = height(r);
			for(int i=0;i<=h;i++){
				printGivenLevel(r,i);
			}
		}
		
		TreeNode* minValueNode(TreeNode* node){
			TreeNode* current=node;
			while(current->left!=NULL){
				current=current->left;
			}
			return current;
		}
		
};

int main(){
	AVLTree obj;
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
				cout<<"AVL INSERT"<<endl;
				cout<<"Enter value of TreeNode to insert in BST: ";
				cin>>val;
				new_node->value = val;
				obj.root = obj.insertRecursive(obj.root , new_node);
				cout<<endl;
				break;
			case 2:
				cout<<"SEARCH"<<endl;
				cout<<"Enter value to search: ";
				cin>>val;
				//new_node creates memory in the heap, so to store heap data(temp data is in heap),
				//we initialize new memeory in heap using new_node
				new_node = obj.iterativeSearch(val);  //new_node is used to deal with heap memory.
				
				if(new_node!=NULL){
					cout<<"Value found"<<endl;
				}
				else{
					cout<<"Value not found"<<endl;
				}
				
				break;
			case 3:
				cout<<"DELETE"<<endl;
				cout<<"Enter value to be deleted: ";
				cin>>val;
				new_node = obj.iterativeSearch(val);
				if(new_node!=NULL){
					//obj.deleteNode(obj.root, val);
					cout<<"Value deleted"<<endl;
				}
				else{
					cout<<"Value not found"<<endl;
				}
				break;
			case 4:
				cout<<"Print/Traversal AVL Tree"<<endl;
				obj.print2D(obj.root,5);  //visual way to print BST
				break;
			case 5:
				cout<<"Level order BFS: ";
				obj.printLevelOrderBFS(obj.root);
				cout<<endl;
				break;
			case 6:
				cout<<"Tree Height"<<endl;
				cout<<"Height: "<<obj.height(obj.root)<<endl; //obj.root means obj is calling data member of BST class.
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
