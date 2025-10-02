class Solution {
public:
    int t[1001][1001];
    bool check(string& s1 , string &s2 ){
        int cur = s1.size() ;
        int prev = s2.size();

        if(cur <= prev || cur-prev != 1){
            return false ;
        }
        int i = 0 ; int j = 0; 
        while(i<prev && j< cur){
            if(s1[j] == s2[i]){
                i++;
            }
            j++;
        }
        return i==prev;
    }
     
     static bool lambda(string & w1 , string & w2){
        return w1.length() < w2.length();
     }
     int f(vector<string>&words , int idx ,int curr) {
        if(curr == words.size()){
            return 0;
        }
       if( idx != -1 && t[curr][idx]  != -1){
        return t[curr][idx];
       }
        int take =0; int nottake =0 ;
        if(  idx ==-1 ||   check(words[curr] , words[idx])  ){
            take = 1+ f(words , curr ,  curr+1);
        }
       nottake =  f(words , idx , curr+1);
       if (idx != -1) {
        t[curr][idx] =  max(take , nottake) ;
       } 
        return max(take ,nottake);
    
     }
    int longestStrChain(vector<string>& words) {
        sort(begin(words) , end(words), lambda);
        memset(t , -1 , sizeof(t));
      
        return f(words , -1 , 0 );
    }
};