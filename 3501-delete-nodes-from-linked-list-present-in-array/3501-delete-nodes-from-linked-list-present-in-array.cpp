


class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numbers(nums.begin(), nums.end());

        ListNode* prev = nullptr;
        ListNode* cur = head;

        while (cur != nullptr) {
            if (numbers.count(cur->val)) {
                if (prev == nullptr) {
                    head = head->next;
                } else {
                    prev->next = cur->next;
                }
            } else {
                prev = cur;
            }
            cur = cur->next;
        }

        return head;
    }
};
