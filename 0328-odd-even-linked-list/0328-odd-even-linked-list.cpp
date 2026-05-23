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
    ListNode* oddEvenList(ListNode* head) {
        // Handle empty list
        if (!head) {
            return nullptr;
        }
      
       
        ListNode* oddCurrent = head;                    // Current odd position node
        ListNode* evenCurrent = head->next;             // Current even position node
        ListNode* evenHead = evenCurrent;              
      
       
        while (evenCurrent && evenCurrent->next) {
           
            oddCurrent->next = evenCurrent->next;
            oddCurrent = oddCurrent->next;
          
          
            evenCurrent->next = oddCurrent->next;
            evenCurrent = evenCurrent->next;
        }
      
        // Connect the end of odd list to the beginning of even list
        oddCurrent->next = evenHead;
      
        return head;
    }
};
