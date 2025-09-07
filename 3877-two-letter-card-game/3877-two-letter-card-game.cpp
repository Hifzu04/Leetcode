
class Solution {
public:
    int score(vector<string>& cards, char x) {
        vector<int> left(10, 0), right(10, 0);
        int xxCount = 0;
        int leftCount = 0, rightCount = 0;

        for (auto& s : cards) {
            if (s[0] == x && s[1] == x) {
                xxCount++;
            } else if (s[0] == x) {
                leftCount++;
                left[s[1] - 'a']++;
            } else if (s[1] == x) {
                rightCount++;
                right[s[0] - 'a']++;
            }
        }

        int maxLeft = 0, maxRight = 0;
        for (int i = 0; i < 10; i++) {
            maxLeft = max(maxLeft, left[i]);
            maxRight = max(maxRight, right[i]);
        }

        int pairLeft = min(leftCount / 2, leftCount - maxLeft);
        int leftover = leftCount - 2 * pairLeft;
        int pairRight = min(rightCount / 2, rightCount - maxRight);
        leftover += rightCount - 2 * pairRight;

        int ans = pairLeft + pairRight + min(leftover, xxCount);
        if (xxCount > leftover) {
            ans += min(pairLeft + pairRight, (xxCount - leftover) / 2);
        }

        return ans;
    }
};
