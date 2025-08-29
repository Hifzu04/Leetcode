class Solution {
   #define ll long long
public:
    long long flowerGame(int n, int m) {
        ll oddn= n%2 ==1 ? n/2+1 : n/2;
        ll oddm = m%2==1 ? m/2+1 : m/2;
        ll evenn = n/2;
        ll evenm = m/2;

     ll ans = (oddn*evenm)+(evenn*oddm);
        return ans;

    }
};