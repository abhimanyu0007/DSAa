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
		
		TreeNode* deleteNode(TreeNode* r, int v){
			if(r==NULL){
				return NULL;
			}
			else if(v < r->value){
				r->left = deleteNode(r->left,v);
			}
			else if(v > r->value){
				r->right = deleteNode(r->right,v);
			}
			else{
				if(r->left == NULL){
					TreeNode* temp = r->right;
					delete r;
					return temp;
				}
				else if(r->right == NULL){
					TreeNode* temp = r->left;
					delete r;
					return temp;
				}
				else{
					TreeNode* temp = minValueNode(r->right);
					r->value = temp->value;
					r->right = deleteNode(r->right, temp->value);
				}
			}
			return r;
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
			case 2:
				cout<<"SEARCH"<<endl;
				cout<<"Enter value to search: ";
				cin>>val;
				//new_node craetes memory in the heap, so to store heap data(temp data is in heap),
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
					obj.deleteNode(obj.root, val);
					cout<<"Value deleted"<<endl;
				}
				else{
					cout<<"Value not found"<<endl;
				}
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
