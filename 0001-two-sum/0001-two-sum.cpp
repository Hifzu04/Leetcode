class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
       for(int i = 0  ; i< nums.size() ; i++){
          int key = target - nums[i] ;
          if(mp.find(key) != mp.end()){
            return {i , mp[key]};
          }
          mp[nums[i]] = i;
       }

       return {}; 
    }
};

// n1 = t - n2 ;
//sort ;
// i = 0 ; j = nums.size() -1 ;

//unordered_map<int, int>mp  //ele , idx ; 