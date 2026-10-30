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
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    ListNode* rever(ListNode*& head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* fwd = NULL;
        while(temp != nullptr){
            fwd = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = fwd;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head == NULL) return true;
        if( head -> next == nullptr) return true;

        ListNode* temp = head;
        ListNode* middle = findMid(head);
        ListNode* head1 = middle -> next;
         
        head1 = rever(head1);
        ListNode* temp1 = head1;

        while(temp != nullptr && temp1 !=nullptr){
            if(temp-> val != temp1 -> val) return false;
            temp = temp -> next;
            temp1 = temp1 -> next;
        }
        return true;


    }
};