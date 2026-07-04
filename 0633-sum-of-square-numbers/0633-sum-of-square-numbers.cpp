class Solution {
public:
    bool judgeSquareSum(int c) {
        
        vector<long long> sqel; 
        for(long long i = 0 ; i*i <=c  ; i++){
            sqel.push_back(i*i);
        }
        for(int i = 0 ; i<sqel.size() ; i++){
           long long target= (long long)c-sqel[i];
           int l = 0 ; int r = sqel.size()-1;
           while(l <= r){
             int mid = l + (r-l)/2;
             if(sqel[mid] == target){
                return true;
             }else if (sqel[mid] < target){
                l = mid+1;
             }else {
                r = mid-1;
             }
           }
        }
        return false ;
    }
};