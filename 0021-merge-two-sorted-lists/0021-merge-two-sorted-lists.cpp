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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0); 
        ListNode* tail = &dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Append the remaining nodes of the non-empty list
        if (list1 != nullptr) {
            while (list1 != nullptr) {
                tail->next = list1;
                tail = tail->next;
                list1 = list1->next;
            }
        } else if (list2 != nullptr) {
            while (list2 != nullptr) {
                tail->next = list2;
                tail = tail->next;
                list2 = list2->next;
            }
        }
        return dummy.next;  // Head of the merged list
    }
};