class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        for (int i = 0; i < arr.size() - 1; i++) {
            if (abs(arr[i + 1] - arr[i]) < minDiff) {
                minDiff = abs(arr[i + 1] - arr[i]);
            }
        }

        vector<vector<int>> ans;
        for (int i = 0; i < arr.size() - 1; i++) {
            if (abs(arr[i + 1] - arr[i]) == minDiff) {
                int a = min(arr[i + 1], arr[i]);
                int b = max(arr[i + 1], arr[i]);
                ans.push_back({a, b});
            }
        }
        return ans;
    }
};