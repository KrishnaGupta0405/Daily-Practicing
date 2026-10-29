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
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* result = new ListNode(0);
        ListNode* temp3 = result;
        while(temp1 != nullptr && temp2 != nullptr){
            ListNode* temp;
            if(temp1 -> val < temp2 -> val){
                temp = new ListNode(temp1 -> val );
                temp3 -> next = temp;
                temp3 = temp3 -> next;
                temp1 = temp1 -> next;
            }
            else if(temp1 -> val > temp2 -> val){
                temp = new ListNode(temp2 -> val );
                temp3 -> next = temp;
                temp3 = temp3 -> next;
                temp2 = temp2 -> next;
            }
            else if(temp1 -> val == temp2 -> val){
                ListNode* val1 = new ListNode(temp1 -> val);
                ListNode* val2 = new ListNode(temp1 -> val);
                temp3 -> next = val1; temp3 = temp3 -> next;
                temp3 -> next = val2; temp3 = temp3 -> next;
                temp1 = temp1 -> next; temp2 = temp2 -> next;
            }
        }

        while(temp1 != nullptr){
            ListNode* temp = new ListNode(temp1 -> val);
            temp3 -> next = temp;
            temp3 = temp3 -> next;
            temp1 = temp1 -> next;
        }
        while(temp2 != nullptr){
            ListNode* temp = new ListNode(temp2 -> val);
            temp3 -> next = temp;
            temp3 = temp3 -> next;
            cout<< temp2 -> val;
            temp2 = temp2 -> next;
        }
        return result -> next;
    }
};