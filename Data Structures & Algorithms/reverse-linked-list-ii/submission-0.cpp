class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (!head || left == right) {
            return head;
        }

        ListNode dummy(0, head);

        ListNode* prev = &dummy;

        // Move prev to the node just before 'left'
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;

        // Reverse nodes from left to right
        for (int i = 0; i < right - left; i++) {

            ListNode* nextNode = curr->next;

            curr->next = nextNode->next;

            nextNode->next = prev->next;

            prev->next = nextNode;
        }

        return dummy.next;
    }
};