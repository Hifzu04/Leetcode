class Solution {
public:
    int t[10004];
     bool f(int idx , vector<int>& nums){
        if(idx == nums.size()-1) return true;
        if(t[idx] != -1) return t[idx];
        for(int i = 1 ; i<= nums[idx] ; i++){
            if(f(idx+i ,nums)){
                return t[idx] = true;
            }
        }

        return t[idx] =  false ;
     }
    bool canJump(vector<int>& nums) {
        memset(t , -1 , sizeof(t));
        return f(0 , nums);
    }
};











//