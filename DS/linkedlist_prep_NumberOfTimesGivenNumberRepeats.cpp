// Number of times a given number repeats in a linked list

#include<bits/stdc++.h>

using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

void push(Node** head, int key){
	Node *new_Node = new Node();
	new_Node->data = key;
	new_Node->next = *head;
	*head = new_Node;

	return;
}

int countAGivenNumber(Node* head, int key){
	Node* current = head;
	int count=0;

	while(current != NULL){
		if(current->data == key)
			count++;
		current = current->next;
	}

	return count;
}

int main(){
	Node*  head = NULL;

/* Use push() to construct below list  
    1->2->1->3->1 */
	push(&head, 1); 
	push(&head, 3); 
	push(&head, 1); 
	push(&head, 2); 
	push(&head, 1); 
  
    /* Check the count function */
	cout << "count of 1 is " << countAGivenNumber(head, 1); 
	return 0; 
}
