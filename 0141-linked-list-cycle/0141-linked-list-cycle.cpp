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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*>visited;

        ListNode* curr = head;
        while(curr != nullptr){
            if(visited.count(curr) >0 ){
                return 1;
            }
            visited.insert(curr);
            curr = curr->next;
        }
        return 0;
    }
};