class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // map<string ,int>mp;
        vector<pair<string, int>> vec;
        unordered_map<string, int> mp;
        for (int i = 0; i< words.size(); i++) {
            string w1 = words[i];
            mp[w1]++;
        }

        for (auto& [x, y] : mp) {
            vec.push_back({x, y});
        }

        sort(vec.begin(), vec.end(), [](auto& a, auto& b) {
            if (a.second != b.second)
                return a.second > b.second;

            return a.first < b.first;
        });
         vector<string>ans;
        for(int i = 0 ; i< k ; i++){
            ans.push_back(vec[i].first)  ;
        }
        return ans;
    }
};

/*
i -2
love - 2
coding - 1
leetcode 1

copy map -> string
using custom sort -
loop k times on string and get the result
*/