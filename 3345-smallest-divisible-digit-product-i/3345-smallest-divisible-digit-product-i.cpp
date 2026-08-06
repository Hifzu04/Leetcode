class Solution {
public:
    int productdigit(int n ){
        int prd = 1;
        while(n>0){
            int unit = n%10;
            prd *= unit;
            n/= 10;

        }
        return prd;
    }
    int smallestNumber(int n, int t) {
        while(!(productdigit(n)%t == 0)){
            n++;
        }
        return n ;
    }
};