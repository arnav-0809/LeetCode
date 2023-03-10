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
    ListNode* h;
public:
    Solution(ListNode* head) {
        h = head;
        srand(time(0)); 
    }
    
    int getRandom() {
        int c = 0, random = 0;
        ListNode* curr = h;
        while(curr)
        {
            c++;
            if(rand() % c == 0)
            {
                random = curr -> val;
            }
            curr = curr -> next;
        }
        return random;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */