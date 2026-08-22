class Solution {
public:
    bool checkDivisibility(int n) {
        int original =n;
        int sum = 0 ;
        int product = 1;
        while(n>0){
            int unit = n%10;
            n/=10;
            sum+=unit;
            product*=unit;
            
        }
      int total = sum + product;
        if (total > 0 && original % total == 0) return true;
        else  return false ;
        
    }
};