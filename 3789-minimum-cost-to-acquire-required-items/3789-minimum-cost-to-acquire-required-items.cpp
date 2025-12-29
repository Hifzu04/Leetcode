class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long p1 = min(cost1 + cost2, costBoth);
        long long p2 = min(cost1, costBoth);
        long long p3 = min(cost2, costBoth);

        int cnt = min(need1, need2);
        int extra1 = need1 - cnt;
        int extra2 = need2 - cnt;

        long long totalCost = 1LL * cnt * p1
                            + 1LL * extra1 * p2
                            + 1LL * extra2 * p3;

        return totalCost;
    }
};