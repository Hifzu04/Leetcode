class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0 ; 
        int n = word.size();
        for(int i=1 ; i<=n ; i++ ){
            if(i <= 8){
                ans++;
            }
            else if (i<= 16){
                ans+=2;
            }else if (i<=24){
                ans+=3;
            }else {
                ans+=4;
            }
        }

        return ans;
    }
};


// 1 - 8 => 1
// 9-16 => 2
//17-24 =. 3 
//24 + => 4 