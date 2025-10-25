class Solution {
public:
    int totalMoney(int n) {
        int cnt = 1;
        int next = 2; 
        int ans = 0 ;
        for(int i = 0 ; i<n; i++){
            ans+=cnt;
            cnt++;
            if((i+1)%7==0){
                cnt = next;
                next++;
            }
        }
        return ans;
    }
};