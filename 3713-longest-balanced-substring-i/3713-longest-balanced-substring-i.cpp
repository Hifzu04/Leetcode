class Solution {
public:
    bool check(vector<int>ch){
        int freq = ch[0];
        for(int  i= 0 ; i<ch.size() ; i++){
            
            if(ch[i] > 0){
               freq = ch[i];
               break;
            }
        }

        for(int  i= 0 ; i<ch.size() ; i++){
            
            if(ch[i] > 0){
              if(ch[i] != freq )
               return false;
            }
        }
        return true;

    }
    int longestBalanced(string s) {
        int n = s.size();
          int maxm = 0 ;
        for (int i = 0; i < n; ++i) {
           vector<int>ch(26,0);
            
            for (int j = i; j < n; ++j) {
                ch[s[j] - 'a']++;
                if(check(ch))
                maxm = max(maxm ,j-i+1);
               
            }
        }
        return maxm; 
    }
};