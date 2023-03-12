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
        map<int, int> m;
        int n = lists.size();
        ListNode* head;
        for(int i = 0; i < n; i++)
        {
            head = lists[i];
            while(head)
            {
                m[head -> val]++;
                head = head -> next;
            }
        }

        ListNode* prev = new ListNode();
        ListNode* curr = prev;
        for(auto it : m)
        {
            for(int i = 0; i < it.second; i++)
            {
                ListNode* nxt = new ListNode(it.first);
                curr -> next = nxt;
                curr = nxt;
            }
        }
        return prev -> next;
    }
};