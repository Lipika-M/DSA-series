//Problem:Search in a linked list
//https://www.geeksforgeeks.org/problems/search-in-linked-list-1664434326/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=search-in-linked-list-1664434326/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, Node* head, int key) {
       bool found=0;
       Node*temp=head;
        while(temp!=NULL){
           if (temp->data==key){
               found=1;
               break;
           }
         
               temp=temp->next;
            
       }
       return found;
    }
};
//approach:traversed the given linked list to find if key is present or not
//TC:O(N)
//SC:O(1)

//Doubly linked list isert at any position
//https://www.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=insert-a-node-in-doubly-linked-list
/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

// Function to insert a new node at given position in doubly linked list.
class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data) {
        Node*temp=new Node(data);
     if(head==NULL){
         head=temp;
         return head;
         }
     if(pos==0){
         temp->next=head;
         head->prev=temp;
         return head;
     }
     Node*p=NULL;
     Node*curr=head;
     int i=0;
     while(i<=pos && curr!=NULL ){
         p=curr;
         curr=curr->next;
         i++;
     }
     if (curr==NULL){
         p->next=temp;
         temp->prev=p;
         return head;
     }
      p->next=temp;
     temp->prev=p; 
     temp->next=curr;
     curr->prev=temp;
    
     return head;
    }
};
//approach:iterated till the position is reached and then inserted the given node there
//TC:O(N) Where N is the given position
//SC:O(1)
