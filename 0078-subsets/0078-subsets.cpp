class Solution {
public:
     vector<vector<int>>ans ;
     void f(vector<int>& nums , int i , vector<int>& temp ){
            if(i == nums.size()){
                ans.push_back(temp);
                return;
            }

            temp.push_back(nums[i]);
            f(nums , i+1 , temp);         //take
            temp.pop_back();         //backtracking
            f(nums , i+1 , temp);       //not take
 
     }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp ;
         f(nums , 0 , temp);
        return ans;
    }
};


/*

1 12 123 2 23 12 123 3 

resursion  ALL POSSIBILITIES

take , skip 

1                     []






*/ 