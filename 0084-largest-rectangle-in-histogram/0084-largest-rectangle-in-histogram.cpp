class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>left; 
        stack<int>right;
        vector<int>leftvec(n) ; vector<int>rightvec(n);

        for(int i = 0 ; i< n ; i++){
            while(!left.empty() && heights[left.top()] >= heights[i]){
                left.pop();
            }
            if(left.empty()){
                leftvec[i] = i;
            }else {
                leftvec[i] = i-left.top()-1;
            }
            left.push(i);
        }

        for(int i = n-1 ; i>=0; i--){
            while(!right.empty() && heights[right.top()]>= heights[i]){
                right.pop();
            }
            if(right.empty()){
                rightvec[i] = n-i-1;
            }else {
                rightvec[i] = right.top()-i -1 ;
            }
            right.push(i);
        }

            int myans = -1 ;
        for(int i =0  ; i<n ; i++){
            int ans = heights[i]*(leftvec[i]+rightvec[i]+1);
            myans = max(ans,myans);
        }
        return myans;


    }
};