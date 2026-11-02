/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = random = nullptr;
    }
};*/

class Solution {
  public:
    void insertAtTail(Node*& head, Node*& tail, int d){
        Node* temp = new Node(d);
        
        if( head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail -> next = temp;
            tail = tail -> next;
            return;
        }
    }
    Node* cloneLinkedList(Node* head) {
        //  Aprroach 1. Make simple LL, then two for loops to connect with random
        // Approach 2. Make LL + Map for oldToNew Node, then temp -> random = map[old-> random]
        
        // Step 1. Make simple LinkedList
        Node* temp = head;
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        while(temp != NULL){
            insertAtTail(cloneHead, cloneTail, temp -> data);
            temp = temp -> next;
        }
        
        // Step 2. Make the Map storing old to New node
        temp = head;
        Node* temp2 = cloneHead;
        unordered_map<Node*, Node*> oldToNew;
        while(temp != NULL){
            oldToNew[temp] = temp2;
            temp = temp -> next;
            temp2 = temp2 -> next;
        }
        
        // Step 3. Now join the random pointer
        temp = head;
        temp2 = cloneHead;
        while(temp2 != NULL){
            temp2 -> random = oldToNew[ temp -> random ];
            temp = temp -> next;
            temp2 = temp2 -> next;
        }
        return cloneHead;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        // Approach 3. Combine both LL (replacement of Map)
    }
};