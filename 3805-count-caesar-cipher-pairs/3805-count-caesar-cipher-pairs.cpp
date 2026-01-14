#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countPairs(vector<string>& words) {
        long long ans = 0;
        unordered_map<string, long long> freq;
        
        for (auto &word : words) {
            int shift = word[0] - 'a';
            string normalized = word;
            for (int i = 0; i < (int)word.size(); i++) {
                // shift each character backward by "shift" with wrap around
                normalized[i] = char('a' + ( (word[i] - 'a' - shift + 26) % 26 ));
            }
            ans += freq[normalized];
            freq[normalized]++; 
        }
        
        return ans;
    }
};
