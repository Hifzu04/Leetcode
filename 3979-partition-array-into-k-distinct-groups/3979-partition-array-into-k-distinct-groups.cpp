class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();

        if(k>n || n%k!= 0) return false ; 
         
        map<int , int>mp;
        for(int i = 0 ; i<n ; i++){
            mp[nums[i]]++;
        }
        for(auto it : mp){
            // if(it.second>k ) {
            //     return false ;
            // }
            if(it.second > n/k) return false; 
        }

        return true;
    }
};