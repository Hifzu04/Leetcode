
class Solution {
public:
    vector<int> ans;
    int minDiff = INT_MAX;
    vector<int> list;

    vector<int> minDifference(int n, int k) {
        // find divisors of n
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                list.push_back(i);
                if (i * i != n) {
                    list.push_back(n / i);
                }
            }
        }
        sort(list.begin(), list.end());

        vector<int> current;
        solve(n, k, current, 0);
        return ans;
    }

private:
    void solve(int n, int k, vector<int>& current, int idx) {
        if (k == 0) {
            if (n == 1) {
                int maxVal = *max_element(current.begin(), current.end());
                int minVal = *min_element(current.begin(), current.end());
                int diff = maxVal - minVal;

                if (diff < minDiff) {
                    minDiff = diff;
                    ans = current;
                }
            }
            return;
        }

        for (int i = idx; i < (int)list.size(); i++) {
            int div = list[i];
            if (n % div == 0) {
                current.push_back(div);
                solve(n / div, k - 1, current, i);
                current.pop_back();
            }
        }
    }
};
