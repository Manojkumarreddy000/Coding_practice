 // iterative program to search of a element in a linked list
#include<bits/stdc++.h>

using namespace std;

class node
{
    public:
        int data;
        node *next;
};

void push(node **head, int key){
    node* new_node = new node();
    new_node->data = key;
    new_node->next = *head;
    *head = new_node;
    return;
}

bool search(node *head, int key){
    node *current = head;
    while (current!=NULL)
    {
        if(current->data==key)
            return true;
        current = current->next;
    }
    return false;
    
}
int main()  
{  
    node* head = NULL;  
    int x = 21;  
  
    push(&head, 10);  
    push(&head, 30);  
    push(&head, 11);  
    push(&head, 21);  
    push(&head, 14);  
  
    search(head, 21)? std::cout<<"Yes" : std::cout<<"No";  
    return 0;  

}
