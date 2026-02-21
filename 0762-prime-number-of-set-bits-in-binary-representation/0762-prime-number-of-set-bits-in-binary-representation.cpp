class Solution {
public:
    int ans = 0 ; 
    bool isPrimary(int n ){
        if(n==1) return false; 
        for(int i = 2; i*i<= n ; i++ ){
            
            if(n!= i && n %i == 0){
                return false;
            }
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        for(int i = left ; i<= right ; i++){
              int set_bits_count = __builtin_popcount(i);
              if(isPrimary(set_bits_count)){
                ans++;
              }
        }
        return ans;

    }
};