/* Circular Linked List Node Structure
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
public:
    vector<Node*> splitList(Node* head) {
        vector<Node*> arr(2, nullptr);

        if (head == nullptr) return arr;

        Node* slow = head;
        Node* fast = head;

        while (fast->next != head &&
               fast->next->next != head) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // For an even-length list, fast reaches the last node.
        // For an odd-length list, fast->next reaches the last node.
        if (fast->next->next == head) {
            fast = fast->next;
        }

        arr[0] = head;
        arr[1] = slow->next;

        fast->next = slow->next;
        slow->next = head;

        return arr;
    }
};
