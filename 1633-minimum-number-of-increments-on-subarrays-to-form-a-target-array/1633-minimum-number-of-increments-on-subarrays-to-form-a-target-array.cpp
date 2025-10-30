class Solution {
public:
    int minNumberOperations(vector<int>& target) {
       
        int tot = target[0];
      
        for (int i = 1; i < target.size(); ++i) {
 
            if (target[i] > target[i - 1]) {
                tot += target[i] - target[i - 1];
            }
        
        }
      
        return tot;
    }
};
