// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int>ans;
//         for(int  i = 0 ; i< nums.size()  ; i++){
//             for(int j = i+1 ; j< nums.size() ; j++) {
//                 if(i != j && nums[i] == target -nums[j]) {
//                    ans.push_back(i);
//                    ans.push_back(j);
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];

            if (mp.count(need)) {
                return {mp[need], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};