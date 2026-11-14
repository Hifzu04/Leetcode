class Solution {
public:
    int t[46];
    int f(int n ){
      
        if(n==0) return 1; 
        if(n<0) return 0;
        
        if(t[n] != -1) return t[n];
        return t[n] =  f(n-1) + f(n-2);

        
    }
    int climbStairs(int n) {
        memset(t , -1 , sizeof(t));
        return f(n);
    }
};


/*

1 - 1 
2 - 1 , 2 
3 - 1 , 2-1 , 1-2
4 - 1 , 1-1-2 , 1-2-1 , 2-1-1 ,2-2     
5- 1 , 1-1-1-2 , 3-2 , 2-3   
// dp => 5 
         3   4 
         2 1   2 3 

        



*/