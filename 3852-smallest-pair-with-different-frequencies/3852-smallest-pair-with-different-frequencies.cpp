class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        map<int,int>mpp;
        int n = nums.size();
        for(auto it : nums){
            mpp[it]++;
        }

        sort(nums.begin() , nums.end());
       vector<int>ans;
        for(int i = 0 ; i< n ; i++){
            int x = nums[i];
            for(int j = i+1 ; j< n ; j++ ){
                int y= nums[j];
                if(x != y && mpp[x] != mpp[y]){
                      ans = {x,y};  
                      return ans;                  
                }
            }
        }

        return {-1,-1};

        

    }
};