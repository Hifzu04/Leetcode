class Solution {
public:
     int getwav(int i ){
        string str = to_string(i);
        int ans = 0;
        if (str.size() <= 2) {
            return 0;
        }
        for(int i = 1 ; i< str.size() -1 ; i++){
            if((str[i] > str[i-1] && str[i] > str[i+1]) || (str[i] < str[i-1] && str[i] < str[i+1]) ) ans++;
            
        }
        return ans;
     }
    int totalWaviness(int num1, int num2) {
        int ans = 0  ;
        for (int i = num1 ; i<= num2 ; i++){
             ans += getwav(i);
            
        }
        return ans ;
    }
};