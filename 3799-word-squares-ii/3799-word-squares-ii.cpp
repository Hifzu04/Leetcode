class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        set<vector<string>> st;
        vector<vector<string>> ans;
        int n = words.size();
        // simply brutue force;

        for (int t = 0; t < n; t++) {
            for (int b = 0; b < n; b++) {
                if (t == b)
                    continue;
                for (int l = 0; l < n; l++) {
                    if (l == t || l == b)
                        continue;
                    for (int r = 0; r < n; r++) {
                        if (r == t || r == b || r == l )
                            continue;

                        if(words[t][0]==words[l][0] && words[t][3]==words[r][0] 
                        && words[b][0]==words[l][3] && words[b][3]==words[r][3]){

                            st.insert({words[t] , words[l] , words[r] , words[b]});     
                        }   
                    }
                }
            }
        }
        for(auto& it : st){
            ans.push_back(it);
        }
        return ans;

    }
};