class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();

        vector<int>ans;
        sort(potions.begin() ,potions.end());
        for(int i = 0 ; i<n ; i++){
            int s =spells[i];
            long long limit = ceil((1.0*success)/s);
            if(limit > potions[m-1]){
                ans.push_back(0);
                continue;
            }
            int idx = lower_bound(potions.begin() , potions.end() , limit) - potions.begin();
            ans.push_back(m -idx);
        }
        return ans ;
    }
};