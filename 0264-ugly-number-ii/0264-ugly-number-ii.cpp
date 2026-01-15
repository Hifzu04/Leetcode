//class Solution {
//public:
    bool isUgly(int n) {
        if (n == 0)
            return false;
        while (n % 2 == 0) {
            n /= 2;
        }
        while (n % 3 == 0) {
            n /= 3;
        }
        while (n % 5 == 0) {
            n /= 5;
        }
        return n == 1;
    }
   // int nthUglyNumber(int n) {
        // int cnt = 0 ;
        // int num = 1 ;
        // while(true){

        //     if(isUgly(num)){
        //         cnt++;
        //         if(cnt == n) return num;
        //     }
        //     num++;

        // }
        // TLE why
        /*
        Ugly numbers ≤ 1,000 → ~86

         Ugly numbers ≤ 10,000 → ~200

        Ugly numbers ≤ 1,000,000 → ~500

        Ugly numbers ≤ 2,000,000,000 → 1690 (this is the max n)  */




        //methhod 2 DP , itrate over only ugly nubmers , ignore nonUgly nubmer TC O(N)
        class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) return 0;
        vector<int> ugly(n+1);
        ugly[1] = 1;
        //pointers intially pointing to first ugly number
        int i2 = 1, i3 = 1, i5 = 1;
        for (int i = 2; i <= n; i++) {
            int next2 =   ugly[i2] * 2;
            int next3 =   ugly[i3] * 3;
            int next5 =   ugly[i5] * 5;
            int nxt = min({next2, next3 , next5});
            ugly[i] = nxt; 
            if (nxt == next2) ++i2;
            if (nxt == next3) ++i3;
            if (nxt == next5) ++i5;
        }
        return ugly[n];
    }
};



