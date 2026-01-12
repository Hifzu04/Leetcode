class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
       vector<bool>check(1e5+1); 
       for(int x : nums){
        check[x] = true;
       }
       vector<int>ans;
       for(int i = 1; i<= nums.size() ; i++){
        if(!check[i]){
            ans.push_back(i);
        }
       
       }
        return ans;
    }
};

