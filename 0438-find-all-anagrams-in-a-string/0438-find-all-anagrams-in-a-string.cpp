class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       vector<int>p_f(26  ,0);
       vector<int>s_f(26, 0);

       for(auto x : p){
          p_f[x - 'a']++;
       }
       vector<int>ans ;
       int j = 0 ;  //left boundary
       for(int i = 0 ; i<s.size() ; i++){
          s_f[s[i] - 'a']++;

             if ( i- j + 1 > p.size()) {
                s_f[s[j] - 'a']--;
                j++;
            }
            if(i-j+1 == p.size() && p_f == s_f){
                   ans.push_back(j);
            }
       }
       return ans;
    }
};

// s = "cbaebabacd", p = "abc"

// if(p.find(s[i])) i++ ;
// else j = i ;
// if (p.size() == j-i +1 ) ans.push_back(i) , j++
