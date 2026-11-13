class Solution {
public:
     int n ;
     unordered_set<string>dict;
    int t[301];
    bool dp(string& s , int idx ){
        if(idx >= n){
            return true;
        }

        if(t[idx] != -1) return t[idx];

        if(dict.find(s) != dict.end()){
            return true;
        }

        
        for(int l = 1 ; l<= n ; l++){
            string temp = s.substr(idx , l);
            if(dict.find(temp) != dict.end() && dp(s , idx+l)) {
                   return  t[idx] =true;
            }
        }
        return t[idx] = false;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
         n = s.size();
         for(auto& x : wordDict){
            dict.insert(x);
         }
         memset(t,  -1 ,sizeof(t) );
         return dp(s , 0);
    }
};


//cant use greedy
/// abca  == ab b ca ; 
//  a bca // a  bca dkdfer 
// if( for a particluar length of substrig after breaking )

//put: s = "leetcode", wordDict = ["leet","code"]
// for(l = idx , ){
//       temp sub = 
//       if(tempsub is present) => check rest of the code 
//  }
