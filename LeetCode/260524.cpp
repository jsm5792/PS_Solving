class Solution {
public:
    vector<int> dp;
    int dfs(int curr, vector<int>& arr, int d, int n)
    {
        if (dp[curr] != -1)
        {
            return dp[curr];
        }

        int max_jumps = 1;
        for(int x=1;x<=d;x++)
        {
            int next_idx = curr + x;
            if(next_idx >= n)
            {
                break;
            }
            if(arr[next_idx] >= arr[curr])
            {
                break;
            }
            max_jumps = max(max_jumps, 1 + dfs(next_idx, arr, d, n));
        }

        for(int x=1;x<=d;x++)
        {
            int next_idx = curr - x;
            if(next_idx < 0)
            {
                break;
            }
            if(arr[next_idx] >= arr[curr])
            {
                break;
            }
            max_jumps = max(max_jumps, 1 + dfs(next_idx, arr, d, n));
        }
        return dp[curr] = max_jumps;
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        dp.assign(n, -1);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i, arr, d, n));
        }

        return ans;
    }
};
