class Solution {
public:
   bool check(int x){
   int cnt[10] = {0};
        if(x == 0) return false;               
        int t = x;
        while(t > 0){
            int d = t % 10;
            if(d == 0) return false;          
            cnt[d]++;
            if(cnt[d] > 9) return false;    
            t /= 10;
        }
        for(int d = 1; d <= 9; ++d){
            if(cnt[d] != 0 && cnt[d] != d) return false;
        }
        return true;
   }
    int nextBeautifulNumber(int n) {


      int ans =0;
      for(int i = n+1 ; ; i++ ){
        if(check(i)){
          return i ;
        }
      }
      
    }
};