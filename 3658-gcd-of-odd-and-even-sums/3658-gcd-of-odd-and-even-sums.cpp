class Solution {
public:
// int getGCD(int a, int b) {
//     if (b == 0) {
//         return a;
//     }
//     return getGCD(b, a % b);
// }

    int gcdOfOddEvenSums(int n) {
       return gcd(n*n , n*(n+1)); 
    }

   //S_n = n/2 [2a + (n-1)*d]
   // for odd = n/2 [2+ (n-1)*2]
   //           for odd = n*n

   //for even = n/2 [2 + 2*n ] = n*(n+1)
};