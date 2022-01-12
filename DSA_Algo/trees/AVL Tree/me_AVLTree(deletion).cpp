#include<iostream>
#define SPACE 10 
using namespace std;

class TreeNode{
	public:
		int value;
		TreeNode* left;
		TreeNode* right;
		
		TreeNode(){
			value = 0;
			left=NULL;
			right=NULL;
		}
		
		TreeNode(int v){
			value= v;
			left=NULL;
			right=NULL;
		}
};

class AVLTree{
	public:
		TreeNode* root;
		AVLTree(){
			root=NULL;
		}
		
		bool isEmpty(){
			if(root==NULL) return true;
			else false;
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
			if(r==NULL) return -1;
			lheight= height(r->left);
			rheight= height(r->right);
			return (1 + max(lheight,rheight));
		}
		
		int getBalanceFactor(TreeNode* n){
			if(n==NULL) return -1;
			return height(n->left) - height(n->right);
		}
		
		TreeNode* rightRotate(TreeNode* y){
			TreeNode* x = y->left;
			TreeNode* T2 = x->right;
			
			x->right = y;
			y->left = T2;
			return x;
		}
		
		TreeNode* leftRotate(TreeNode* x){
			TreeNode* y = x->right;
			TreeNode* T2 = y->left;
			
			y->left = x;
			x->right =T2;
			return y;
		}
		
		TreeNode* insertRecursive(TreeNode* r, TreeNode* new_node){
			if(r==NULL){
				r=new_node;
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
			if(bf>1 && new_node->value < r->left->value) return rightRotate(r);
			if(bf<-1 && new_node->value > r->right->value) return leftRotate(r);
			if(bf>1 && new_node->value > r->left->value){
				r->left = leftRotate(r->left);
				return rightRotate(r);
			}
			if(bf<-1 && new_node->value < r->right->value){
				r->right= rightRotate(r->right);
				return leftRotate(r);
			}
			return r;
		}
		
		TreeNode* minValueNode(TreeNode* node){
			//if you use directly use n for traversing then at line 115 see r->right is there, then at r->right min value will get inserted in main code
			//and all between nodes will get skipped bcouz r->right will directly store min value, so to avoid this we another temporary variable.
			TreeNode* current= node;
			while(current->left != NULL){
				current = current->left;
			}
			return current;
		}
		
		TreeNode* recursiveSearch(TreeNode* r, int val){
			if(r==NULL || r->value==val) return r;
			else if(val < r->value) return recursiveSearch(r->left,val);
			else return recursiveSearch(r->right,val);
		}
		
		TreeNode* deleteNode(TreeNode* r, int v){
			if(r==NULL) return NULL;
			else if(v < r->value) r->left= deleteNode(r->left, v);
			else if(v > r->value) r->right= deleteNode(r->right, v);
			else{
				if(r->left == NULL){
					TreeNode* temp = r->right;
					delete r;
					return temp;
				}
				else if(r->right ==NULL){
					TreeNode* temp= r->left;
					delete r;
					return temp;
				}
				else{
					TreeNode* temp = minValueNode(r->right);
					r->value = temp->value;
					r->right = deleteNode(r->right, temp->value);
				}
			}
			
			int bf = getBalanceFactor(r);
			if(bf == 2 && getBalanceFactor(r->left)>=0) return rightRotate(r);
			else if(bf == 2 && getBalanceFactor(r->left)==-1){
				r->left= leftRotate(r->left);
				return rightRotate(r);
			}
			else if(bf==-2 && getBalanceFactor(r->right)<=-0) return leftRotate(r);
			else if(bf==-2 && getBalanceFactor(r->right)==1){
				r->right= rightRotate(r->right);
				return leftRotate(r);
			}
			return r;
		}
};

int main(){
	
	AVLTree obj;
	int option,val;
	
	do{
		cout<<"Select number to perform particular operation"<<endl;
		cout<<"1. Insert Node"<<endl;
		cout<<"2. Delete Node"<<endl;
		cout<<"3. Print AVL Tree"<<endl;
		cout<<"4. Clear Screen"<<endl;
		cout<<"-1 Exit Program"<<endl;
		
		cin>>option;
		TreeNode* new_node = new TreeNode();
		
		switch(option){
			case -1:
				break;
			case 1:
				cout<<"AVL INSERT"<<endl;
				cout<<"Enter value of TreeNode to insert in BST: ";
				cin>>val;
				new_node->value= val;
				obj.root= obj.insertRecursive(obj.root, new_node);
				cout<<endl;
				break;
			case 2:
				cout<<"DELETE"<<endl;
				cout<<"Enter value to be deleted"<<endl;
				cin>>val;
				new_node = obj.recursiveSearch(obj.root,val);
				if(new_node!=NULL){
					obj.root= obj.deleteNode(obj.root, val);
					cout<<"Value deleted"<<endl;
				}
				else{
					cout<<"Value not found"<<endl;
				}
				break;
			case 3:
				cout<<"Print AVL Tree"<<endl;
				obj.print2D(obj.root,5);
				break;
			case 4:
				system("cls");
				break;
			default:
				cout<<"Enter proper option number"<<endl;
				break;
		}
	}
	while(option!=0);
	return 0;
}
