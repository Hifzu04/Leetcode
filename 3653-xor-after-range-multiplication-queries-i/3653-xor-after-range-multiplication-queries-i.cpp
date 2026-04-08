class Solution {
public:
    long long MOD = 1000000007;
    #define ll long long
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(const auto &q : queries){
            int  l = q[0];
              int r = q[1];
            int k = q[2];
            int v = q[3];
            for(int  i =l ; i<= r ; i+=k ){
                ll prod = (ll)nums[i]*v %MOD;
                nums[i] = (int)prod;
            }
            
        }
        long long ans = 0 ;
        for(int i = 0 ; i<nums.size() ; i++){
            ans^= nums[i];
        }
        return ans ;
    }
};