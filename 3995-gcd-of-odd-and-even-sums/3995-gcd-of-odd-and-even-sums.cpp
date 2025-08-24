class Solution {
public:
//    long long gcd_template(int  a, int b) {
//     while (b != 0) {
//         int temp = b;
//         b = a % b;
//         a = temp;
//     }
//     return a;
// }
    int gcdOfOddEvenSums(int n) {
       return gcd(n*n , n*(n+1)); 
    }
};