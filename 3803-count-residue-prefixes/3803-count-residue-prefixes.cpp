class Solution {
public:
    int residuePrefixes(string s) {
      set<int>st;
      int cnt =1 ; int ans = 0 ;


        for(auto& it : s){
               st.insert(it);
               if(st.size() == cnt%3)
                    ans++;
                
             


                cnt++;
        }
        return ans ;
    }
};