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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i = 0;i<lists.size();i++)
        {
            while(lists[i]!=NULL)
            {
                pq.push(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }
        ListNode* list = new ListNode(-1);
        ListNode* temp = list;

        while(!pq.empty())
        {
            temp->next = new ListNode(pq.top());
            pq.pop();
            temp = temp->next;
        }
        return list->next;
    }
};