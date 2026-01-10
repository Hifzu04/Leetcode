class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>ans;
        for(int i= 0 ; i<2*nums.size() ; i++){
            int t = i;
            if(t>= nums.size()){
                t -= nums.size();
                ans.push_back(nums[t]);
            }else {
                ans.push_back(nums[t]);
            }
            
            
        }
        
        return ans;
    }
};