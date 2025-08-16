

#include <bits/stdc++.h>
using ll = long long;
#define f(i, n) for (ll i = 0; (i) < (n); (i)++)
using namespace std;
#define yes cout << "YES\n"
#define no cout << "NO\n"

int countIslands(vector<vector<int>> &grid, int k)
{
    int r = grid.size();
    int c = grid[0].size();
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            sum += grid[i][j];
            if (sum % k == 0)
            {
                ans++;
                sum = 0;
            }
        }

        
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)

    {
        int  k ; cin>>k;
        vector<vector<int>>grid = {{0,2,1,0,0},{0,5,0,0,5},{0,0,1,0,0},{0,1,4,7,0},{0,2,0,0,8}};
        
        int answer =  countIslands(grid , k);
        cout<<answer;
    }
    

    return 0;
}