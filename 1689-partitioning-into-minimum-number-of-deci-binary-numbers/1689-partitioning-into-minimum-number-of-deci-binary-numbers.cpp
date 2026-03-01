class Solution {
public:
    int minPartitions(string n) {
        int maxm =0 ;
       for(int i = 0 ; i< n.size() ; i++){
             maxm = max(maxm , n[i]-'0');

       }

       return maxm;
    }
};