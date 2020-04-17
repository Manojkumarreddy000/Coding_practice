// simple implimentation of binary search tree

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

int main(){
	BST b, *root = NULL; 
    root = b.Insert(root, 50); 
    b.Insert(root, 30); 
    b.Insert(root, 20); 
    b.Insert(root, 40); 
    b.Insert(root, 70); 
    b.Insert(root, 60); 
    b.Insert(root, 80); 
					  
    b.Inorder(root); 
    return 0; 
} 
