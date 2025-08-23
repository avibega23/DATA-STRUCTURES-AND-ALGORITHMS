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
        ListNode* finKthNode(ListNode* head,int k)
        {
            k-=1;
            ListNode* temp = head;
            while(k>0)
            {
                k--;
                temp = temp->next;
            }
            return temp;
        }
        int findLength(ListNode* head)
        {        
            int cnt = 0;
            ListNode* temp = head;
            while(temp != NULL)
            {
                cnt++;
                temp = temp->next;
            }
            return cnt;
        }
        ListNode* reverseLL(ListNode* head)
        {
            ListNode *prev = NULL;
            ListNode *temp = head;
    
            while (temp != NULL)
            {
                ListNode *front = temp->next;
                temp->next = prev;
                prev = temp;
                temp = front;
            }
            return prev;
        }
        ListNode* rotateRight(ListNode* head, int k) {
            if(!head || !head->next) return head;
            int length = findLength(head);
    
            k = k%length;
            
            if(k==0) return head;
    
            ListNode* newNode =  reverseLL(head);
    
            ListNode* kthNode = finKthNode(newNode,k);
    
            ListNode* nextNode = kthNode->next;
    
            kthNode->next = NULL;
    
            kthNode = reverseLL(newNode);
    
    
            head = reverseLL(nextNode);
    
            newNode->next = head;
    
            return kthNode;
        }
    };