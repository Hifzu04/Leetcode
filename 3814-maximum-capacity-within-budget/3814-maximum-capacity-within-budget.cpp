class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {

        int n = costs.size();
        vector<pair<int, int>> p(n);
        vector<int> prefMax(n ,0);

        for (int i = 0; i < n; i++) {
            p[i] = {costs[i], capacity[i]};
        }

        sort(p.begin(), p.end());

        int maxm = INT_MIN;
        for (int i = 0; i < n; i++) {

            if (maxm <= p[i].second) {
                maxm = p[i].second;
            }
            prefMax[i] = maxm;
        }
        int ans = 0;
        for (auto& v : p) {
            if (v.first < budget) {
                ans = max(ans, v.second);
            }
        }
        
        for(int i = n-1 ; i> 0 ; i--){
            int firstinvest = budget - p[i].first;
            if(firstinvest <= 0) continue;
            int r = i-1;
            int l = 0;
            int targetidx = -1;
            while(l<=r){
                int mid = l+ (r-l)/2;
                if(p[mid].first < firstinvest){
                     targetidx = mid;
                     l=mid+1;
                }else {
                    r= mid-1;
                }
            }
            if(targetidx != -1)
            ans = max(ans ,p[i].second + prefMax[targetidx]);


        }

        return ans;



    }
};