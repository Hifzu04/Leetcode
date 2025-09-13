class Solution {
public:
    int maxFreqSum(string s) {
        map<char,int>mpp;
        for(int i =0  ; i<s.size() ; i++){
            mpp[s[i]]++;
        }
        int maxv = 0;
        int maxc= 0;
        for(auto it : mpp){
            if(it.first == 'a' || it.first == 'e' || it.first == 'i' || it.first == 'o' || it.first == 'u' ){
                if(it.second > maxv){
                    maxv = it.second;
                }
            }
            else {
                if(it.second > maxc){
                    maxc = it.second;
                }
            }
        }
        return maxv+maxc;
    }
};