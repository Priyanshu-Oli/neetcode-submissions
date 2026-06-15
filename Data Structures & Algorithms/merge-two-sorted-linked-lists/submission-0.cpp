class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode* l1 = list1;
        ListNode* l2 = list2;

        ListNode* list3 = new ListNode();
        ListNode* l3 = list3;

        while (l1 && l2) {

            if (l1->val <= l2->val) {
                l3->val = l1->val;
                l1 = l1->next;
            } else {
                l3->val = l2->val;
                l2 = l2->next;
            }

            if (l1 || l2) {
                l3->next = new ListNode();
                l3 = l3->next;
            }
        }

        while (l1) {

            l3->val = l1->val;
            l1 = l1->next;

            if (l1) {
                l3->next = new ListNode();
                l3 = l3->next;
            }
        }

        while (l2) {

            l3->val = l2->val;
            l2 = l2->next;

            if (l2) {
                l3->next = new ListNode();
                l3 = l3->next;
            }
        }

        return list3;
    }
};