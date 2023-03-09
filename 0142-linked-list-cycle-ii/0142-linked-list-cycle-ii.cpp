/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)
        {
            return NULL;
        }

        ListNode* slow = head, *fast = head, *entry = head;
        while(fast -> next && fast -> next -> next)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            while(fast == slow)
            {
                while(slow != entry)
                {
                    slow = slow -> next;
                    entry = entry -> next;
                }
                return slow;
            }
        }
        return NULL;
    }
};