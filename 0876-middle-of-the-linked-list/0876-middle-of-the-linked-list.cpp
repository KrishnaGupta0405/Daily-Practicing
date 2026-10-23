
class Solution {
public:
    int getLen(ListNode* head) {
        int le = 0;
        while (head != nullptr) {
            le++;
            head = head->next;
        }
        return le;
    }

    ListNode* middleNode(ListNode* head) {
        int le = getLen(head);
        int m = le / 2;

        ListNode* temp = head;
        for (int i = 0; i < m; i++) {
            temp = temp->next;
        }

        return temp;
    }
};
