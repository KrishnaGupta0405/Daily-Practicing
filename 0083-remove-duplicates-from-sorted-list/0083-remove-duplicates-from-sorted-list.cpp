/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void deleteDup(ListNode*& head){
        ListNode* toDelete = head -> next;
        head -> next = head -> next -> next;
        delete toDelete;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return head;

        ListNode* temp = head;
        while(temp -> next != nullptr){
            if(temp -> val == temp -> next -> val ){
                deleteDup(temp);
            }
            if(temp -> next != nullptr && temp -> next -> val != temp -> val) temp = temp -> next;
        }
        return head;
    }
};