class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
     set<int>st;
       int n =nums.size();
       int ans = 0;
       for(int i = 0 ; i< n ; i++){
        int sum =0 ; 
         st.clear();
        for(int j =i ; j<n ;j++){
            st.insert(nums[j]);
            sum += nums[j];
            if(st.find(sum) != st.end()) ans++;
        }
        //empty thr st
       
       }

       return ans ;

    }
};