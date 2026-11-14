class Solution {
public:
   // (O(N)^2)  tle
    int lengthOfLongestSubstring(string s) {
         int left = 0 ; 
         unordered_set<char>st;
         int ans = 0 ;
         for(int r = 0 ; r<s.size() ; r++){
            while(st.find(s[r]) != st.end()){
                st.erase(s[left]);
                left++ ;
            }
            st.insert(s[r]);
            ans = max(ans , r-left +1);
         }
         return ans;
    }
};

/*

 s =


*/