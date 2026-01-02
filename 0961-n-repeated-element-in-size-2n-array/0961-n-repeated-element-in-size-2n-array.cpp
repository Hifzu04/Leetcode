class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
       map<int,int>mp;
       int ans = 0 ;
       for(auto &it : nums){
        mp[it]++;
       } 
       for(auto it : mp){
        if(it.second >1){
            ans = it.first;
        }
       }
       return ans ;

    }
};