// a basic stack operation using linked list

#include<bits/stdc++.h>
using namespace std;
class StackNode{
	public:
		int data;
		StackNode* next;
};

StackNode* newNode(int x){
	StackNode* stackNode = new StackNode();
	stackNode->data = x;
	stackNode->next = NULL;
	return stackNode;

}

int isEmpty(StackNode* root){
	return !root;
}

void push(StackNode** root, int x){

	StackNode* stackNode = newNode(x);
	stackNode->next = *root;

	*root = stackNode;

	cout<<x<<" Pushed to the stack\n";
}

int pop(StackNode** root){
	if(isEmpty(*root))
	return INT_MIN;

	StackNode* tmp = *root;
	*root = (*root)->next;

	int popped = tmp->data;

	delete(tmp);
	return popped;

}

int peek(StackNode* root){
	if(isEmpty(root))
		return INT_MIN;
	return root->data;
}

int main(){
	StackNode* root = NULL;


	push(&root, 10);
	push(&root, 20);
	push(&root, 30);

	cout<<pop(&root)<< " Popped from the stack\n";
	cout<<" Top element is "<<peek(root);

	return 0 ;

}
