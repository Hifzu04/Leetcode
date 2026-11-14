class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string ,vector<string> >mp;
        
        for(int i = 0 ; i< strs.size() ; i++){
           string temp = strs[i];
           sort(strs[i].begin() ,strs[i].end());
           mp[strs[i]].push_back(temp);
        }

        for(auto [x, y] : mp){
            ans.push_back(y);
        }

        return ans;

    }
};

/*
strs = ["eat","tea","tan","ate","nat","bat"]
// store sorted version of each string in hash 
aet --> eat , tea , ate
//each val of hash table will be one grp




*/

