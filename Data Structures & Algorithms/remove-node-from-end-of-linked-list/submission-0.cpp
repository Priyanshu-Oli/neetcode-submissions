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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = reverse(head);

        if(n==1){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return reverse(head);

        }
        ListNode* prev = head;
        ListNode* curr = head;

        for(int i =1;i<n;i++){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;

        return reverse(head);
    }
    ListNode* reverse(ListNode*head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr  = nextNode;
        }
        return prev;
    }
};
