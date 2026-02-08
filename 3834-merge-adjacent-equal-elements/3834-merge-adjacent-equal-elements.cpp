class Solution {
public:
    typedef long long ll;

    vector<ll> mergeAdjacent(vector<int>& nums) {
        stack<ll> st;

        for (int x : nums) {
            ll cur = x;

            while (!st.empty() && st.top() == cur) {
                cur += st.top();
                st.pop();
            }

            st.push(cur);
        }

        vector<ll> answer;
        while (!st.empty()) {
            answer.push_back(st.top());
            st.pop();
        }

        reverse(answer.begin(), answer.end());
        return answer;
    }
};
