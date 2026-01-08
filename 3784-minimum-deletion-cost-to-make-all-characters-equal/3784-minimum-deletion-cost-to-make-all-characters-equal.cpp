//map[char][costs]; mpp[char[i]] += cost[i];
//totsum of costs ; for(auto& it : mpp ) totsum =+ it->second; maxm = max(maxm , it->sec);
//return tot- maxm;

 
class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        map<char, long long>mpp;
        for(int i = 0 ; i<s.size() ; i++){
             mpp[s[i]] += cost[i];
        }
        long long  totsum = 0 ; 
        long long maxm= INT_MIN;
        for(const auto& it : mpp){
            totsum += it.second;
           maxm =  max(maxm , it.second);
        }
        return totsum - maxm;
    }
};