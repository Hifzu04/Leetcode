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
   ListNode* mergetwoSortedList(ListNode* l1 , ListNode* l2){
    if(!l1) return l2;
    if(!l2) return l1; 

    if(l1->val <= l2->val){
        l1->next = mergetwoSortedList(l1->next , l2);
        return l1;    //head
    }else {
        l2->next =  mergetwoSortedList(l1 , l2->next );
        return l2;  //head
    }

    return NULL;
   }
    ListNode* partitionandmerge(int s , int e , vector<ListNode*> & lists){
        if(s == e){
            return lists[s];
        }
        if(s > e) {
            return NULL;
        }

        int mid = s + (e-s)/2 ;
         ListNode* l1 = partitionandmerge(s, mid , lists);
         ListNode* l2 = partitionandmerge(mid+1 , e , lists);
         return mergetwoSortedList(l1 , l2);

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        if(n== 0 ){
            return NULL ; 
        }
        return partitionandmerge(0 , n-1 , lists);

    }
};