class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        if(words.empty()) return ans;

        string prevSorted = "";
        for (const string &w : words) {
            string s = w;                
            sort(s.begin(), s.end());    
            if (s != prevSorted) {
                ans.push_back(w);        
                prevSorted = s;
            }
           
        }
        return ans;
    }
};
