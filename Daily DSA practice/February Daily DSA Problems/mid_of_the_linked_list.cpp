class Solution {
    public:
        ListNode* middleNode(ListNode* head) {
            ListNode* hare = head;
            ListNode* turtoise = head;
    
            while (hare != NULL && hare->next != NULL)
            {
                hare = hare->next->next;
                turtoise = turtoise->next;
            }
            return turtoise;
        }
    };