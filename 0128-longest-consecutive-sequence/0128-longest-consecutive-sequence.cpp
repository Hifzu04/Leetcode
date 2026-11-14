class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        for (auto x : nums)
            st.insert(x);
        int ans = 0; 
        for (auto x : st) {
            if (st.find(x - 1) == st.end()) { // curr ele is small of its seq {}
                 int cnt  = 1 ; 
                 int temp = x;
                 while(st.find(temp+1) != st.end()){
                    cnt++;
                    temp++;
                 }
                 ans = max (ans , cnt);
            }
        }
        return ans;
    }
};

// sort - O(NlogN)
//  vec<int>vec(1e5);      // -  1 2 3 4 --  ---- -- 100 ----200
//  vec[nums[i]] = nums[i]
// for in vec : if(vec[i] ==1) len++ ;

/*
(O(N)
put all in unordered_set();
iterate over set : if  (st.find(x-1)== st.end) //smallest el of a cons seq
   int cnt =1 ; while(st.find(x+1)) ans++;



*/

//