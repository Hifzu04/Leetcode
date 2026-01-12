class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>ans(2 , -1);
        map<int, int>ms;
        for(int i = 0 ; i< nums.size() ; i++){
            ms[nums[i]]++;
        }
          int cnt = 1  ;
        for(auto it : ms){
            
             if(it.first != cnt) {ans[1] = cnt; break;}
             cnt++;
    
        }
        for(auto it: ms)
         if(it.second > 1) {ans[0] = it.first; break;}

       if(ans[1] == -1) ans[1] = cnt;
        return ans;

       // 1--> 1 , 2-->2 , 03->   ,4 ->1
       //1->2
    }
};