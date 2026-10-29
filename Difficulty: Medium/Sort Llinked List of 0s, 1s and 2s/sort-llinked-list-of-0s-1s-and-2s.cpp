/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void insertAtTail(Node* tail, int data){
        Node* temp = new Node(data);
        tail -> next = temp;
        tail = tail -> next;
    }
    Node* segregate(Node* head) {
        // code here
        
        //Approach 1, counting and changing the values
        Node* temp = head;
        int oneCount = 0;
        int twoCount = 0;
        int zeroCount = 0;
        while(temp != NULL){
            if(temp->data == 0) zeroCount ++;
            if(temp->data == 1) oneCount ++;
            if(temp->data == 2) twoCount ++;
            temp = temp -> next;
        }
        
        temp = head;
        while(temp != NULL){
            if(zeroCount>0) {temp-> data = 0; zeroCount--;}
            else if(oneCount>0) {temp-> data = 1; oneCount--;}
            else if(twoCount>0) {temp-> data = 2; twoCount--;}
            temp = temp -> next;
        }
        return head;
        
        // Approach 2. in place data replacement
        
        // Node* zeroHead = new Node(0);
        // Node* zeroTail = zeroHead;
        // Node* oneHead = new Node(1);
        // Node* oneTail = oneHead;
        // Node* twoHead = new Node(2);
        // Node* twoTail = twoHead;
        
        // Node* temp = head;
        // while(temp != NULL){
        //     if(temp -> data == 0) insertAtTail(zeroTail, 0);
        //     if(temp -> data == 1) insertAtTail(oneTail, 1);
        //     if(temp -> data == 2) insertAtTail(twoTail, 2);
        //     temp = temp -> next;
        // }
        
        // if(oneTail != oneHead){
        //     zeroTail -> next = oneHead -> next;
        // }
        // else{
        //     oneTail -> next = twoHead -> next;
        // }
        // oneTail -> next = twoHead -> next;
        // head = zeroHead -> next;
        // return head;
    }
};