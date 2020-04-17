// simple implimentation of binary search tree with delete node functionality

#include<bits/stdc++.h>

using namespace std;

class BST{
private:
	int data;
	BST *left,*right;
public:
	BST();
	BST(int x);
	BST* BSTSearch(BST *root, int key);
	BST* Insert(BST *root, int key);
	void Inorder(BST *root);
	BST* deleteNode(BST *root,int key);
	BST* minValueNode(BST *root);

};

BST::BST():data(0),left(NULL),right(NULL){}

BST::BST(int x){
	data = x;
	left=right=NULL;
}

BST* BST::BSTSearch(BST *root, int key){
	if(root == NULL || root->data==key )
		return root;
	if(key<root->data)
			return BSTSearch(root->left,key);
	return BSTSearch(root->right,key);

}

BST* BST::Insert(BST *root, int key){
	if(root == NULL)
		return new BST(key);
	if(key<root->data)
		root->left = Insert(root->left, key);
	else
		root->right = Insert(root->right, key);
	return root;

}


void BST::Inorder(BST *root){
	if(root == NULL)
		return;

	Inorder(root->left);
	cout<<root->data<<endl;
	Inorder(root->right);

}

BST* BST::minValueNode(BST *root){
	BST *current =root;

	while(current and current->left != NULL)
		current = current->left;
	return current;
}

BST* BST::deleteNode(BST *root, int key){
		if(root == NULL )
			return root;
		if(key<root->data)
			root->left = deleteNode(root->left,key);
		else if(key>root->data)
			root->right = deleteNode(root->right,key);
		else{
			if(root->left == NULL){
				BST *tmp = root->right;
				free(root);
				return tmp;
			}

			else if(root->right == NULL){
				BST *tmp = root->left;
				free(root);
				return(root->left);
			}

			BST *tmp = minValueNode(root->right);
			root->data = tmp->data;
			root->right = deleteNode(root->right, tmp->data);
		}
		return root;
}


int main(){
	BST b,*root = NULL;
    root = b.Insert(root, 50); 

	b.Insert(root, 30); 
	b.Insert(root, 20); 
	b.Insert(root, 40); 
	b.Insert(root, 70); 
	b.Insert(root, 60); 
	b.Insert(root, 80); 
	  
	cout << "Inorder traversal of the given tree \n"; 
	b.Inorder(root); 
							    
	cout<<"\nDelete 20\n"; 
	root =b.deleteNode(root, 20); 
	cout<<"Inorder traversal of the modified tree \n"; 
	b.Inorder(root); 
													    
	cout<<"\nDelete 30\n"; 
	root = b.deleteNode(root, 30); 
	cout<<"Inorder traversal of the modified tree \n"; 
	b.Inorder(root); 
									    
	cout<<"\nDelete 50\n"; 
	root = b.deleteNode(root, 50); 
	cout<<"Inorder traversal of the modified tree \n"; 
	b.Inorder(root); 
	
	return 0; 
} 
