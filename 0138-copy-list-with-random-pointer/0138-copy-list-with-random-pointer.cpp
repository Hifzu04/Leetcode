/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
     //insert 
    Node* curr = head; 
    while(curr) {
        Node* currnxt = curr->next;
        curr->next = new Node(curr->val);
        curr->next->next = currnxt;
        curr = currnxt ;
    }

    //Assign random 
    curr = head;
    while(curr && curr->next){
        if(curr->random == NULL){
            curr->next->random = NULL;

        }else {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }

    //seperate 
    Node* newhead = head->next;
    Node* newcurr = newhead ; 
    curr= head; 
    while (curr && newcurr){
        curr->next = curr->next ? curr->next->next : NULL;
        newcurr->next = newcurr->next ?  newcurr->next->next : NULL; 
        curr = curr ->next ; 
        newcurr = newcurr->next;
    }
    return newhead;


    }
};