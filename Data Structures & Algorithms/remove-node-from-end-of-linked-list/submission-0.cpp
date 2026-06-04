class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;

        int l = 0;
        ListNode* temp = head;
        while(temp) {
            l++;
            temp = temp->next;
        }

        int i = l - n;
        temp = &dummy;
        while(i--) {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        return dummy.next;
    }
};
