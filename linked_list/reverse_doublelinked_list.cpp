#include<iostream>

using namespace std;

typedef struct DListNode{
		int data;
		DListNode *next;
		DListNode *prev;
}DListNode;

DListNode* reverse_Dlinkedlist(DListNode* root){
		if(root == NULL|| root->next == NULL)
				return root;

		DListNode *Cur,*Prev,*Next;
		Prev = root;
		Cur = root->next;
		Next = Cur->next;

		Prev->next = NULL;
		Prev->prev = Cur;
		while(Cur!=NULL){
			Cur->prev = Cur->next;
			Cur->next  = Prev;
			Prev = Cur;
			Cur = Cur->prev;

		}
		return Prev;
}

void push(DListNode** head_ref, int new_data)  
{  
    /* allocate node */
    DListNode* new_node = new DListNode(); 
  
    /* put in the data */
    new_node->data = new_data;  
      
    /* since we are adding at the beginning,  
    prev is always NULL */
    new_node->prev = NULL;  
  
    /* link the old list off the new node */
    new_node->next = (*head_ref);      
  
    /* change prev of head node to new node */
    if((*head_ref) != NULL)  
    (*head_ref)->prev = new_node ;  
  
    /* move the head to point to the new node */
    (*head_ref) = new_node;  
}  
  
/* Function to print nodes in a given doubly linked list  
This function is same as printList() of singly linked list */
void printList(DListNode *node)  
{  
    while(node != NULL)  
    {  
        cout << node->data << " ";  
        node = node->next;  
    }  
}  
  
/* Driver code */
int main()  
{  
    /* Start with the empty list */
    DListNode* head = NULL;  
      
    /* Let us create a sorted linked list to test the functions  
    Created linked list will be 10->8->4->2 */
    push(&head, 2);  
    push(&head, 4);  
    push(&head, 8);  
    push(&head, 10);  
      
    cout << "Original Linked list" << endl;  
    printList(head);  
      
    /* Reverse doubly linked list */
    head = reverse_Dlinkedlist(head);  
      
    cout << "\nReversed Linked list" << endl;  
    printList(head);          
      
    return 0; 
} 



