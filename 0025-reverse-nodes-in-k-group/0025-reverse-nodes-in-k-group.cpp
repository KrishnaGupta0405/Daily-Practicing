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
    ListNode* reverseKgroups(ListNode* head, int k) {
        ListNode* check = head;

        // Check whether k nodes are available
        for (int i = 0; i < k; i++) {
            if (check == NULL) return head;
            check = check->next;
        }

        ListNode* prevptr = NULL;
        ListNode* curr = head;
        ListNode* nextptr = NULL;
        int count = 0;

        // Reverse k nodes
        while (curr != NULL && count < k) {
            nextptr = curr->next;
            curr->next = prevptr;
            prevptr = curr;
            curr = nextptr;
            count++;
        }

        // Connect the remaining list
        head->next = reverseKgroups(nextptr, k);

        return prevptr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverseKgroups(head, k);
    }
};