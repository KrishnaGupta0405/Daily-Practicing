/* Structure of linked list Node
class Node {
public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/
class Solution {
  public:
  
    void deleteDup(Node*& head){
        Node* toDelete = head -> next;
        head -> next = head -> next -> next;
        delete toDelete;
    }
    // Node* removeDuplicates(Node* head) {
    //     // Approach 1. double for loop, to check if i == j, -> O(n^2)
    //     // Approach 2. Sort the LL then simple check -> O(nlogn)
    //     // Approach 3. Visited array or map to check if visited == true ?
    //     if(head == NULL || head -> next == nullptr) return head;
    //     map<int, bool> visited;
    //     Node* temp = head;
    //     visited[temp -> data] = true;
    //     while(temp -> next != nullptr){
    //         if(visited[temp -> next -> data] == true){
    //             deleteDup(temp);
    //         }
    //         else{
    //             visited[temp-> next -> data] = true;
    //         }
    //         if((temp -> next != nullptr) &&
    //             (temp -> next -> data != temp -> data))
    //         {
    //             temp = temp -> next;
    //         }
    //     }
    //     return head;
        
    // }
    Node* removeDuplicates(Node* head) {
        map<int, bool> visited;
        Node* temp = head;

        if (head == nullptr) return head;

        visited[temp->data] = true;

        while (temp->next != nullptr) {
            if (visited[temp->next->data]) {
                Node* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
            }
            else {
                visited[temp->next->data] = true;
                temp = temp->next;
            }
        }

        return head;
    }
};