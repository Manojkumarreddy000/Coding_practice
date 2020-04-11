#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
	int data;
	Node *next;
};

int getLength(Node* head){
	Node* current = head;
	int count = 0;
	
	while(current != NULL){
		count++;
		current= current->next;
	}

	return count;
}

void push(Node** head, int key){
	
	Node* new_node = new Node();
	new_node->data = key;
	new_node->next = *head;
	*head = new_node; 

}

void NthFromTheEnd(Node* head, int index){
	Node* current = head;
	int len = getLength(current);
	
	if(len<index)
		return;

	for(int i=1;i<len-index;i++){
		current = current->next;
	}
	
	cout<<current->data<<endl;

	return;
}

int main() 
{ 
    /* Start with the empty list */
    struct Node* head = NULL; 
  
    // create linked 35->15->4->20 
    push(&head, 20); 
    push(&head, 4); 
    push(&head, 15); 
    push(&head, 35); 
  
    NthFromTheEnd(head, 4); 
    getchar();
    return 0; 
} 
