class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans ="" ; 
        string alphabet = "zyxwvutsrqponmlkjihgfedcba";
       for(auto& word : words){
           int sum =0;
           for(int i =0 ; i<word.size() ; i++){
               sum += weights[word[i] -'a'];
           }
           int idx = sum%26;
           
           ans.push_back(alphabet[idx]);
       }

        return ans ;
    }
};