class Solution {
public:
    int minMoves(vector<int>& nums, int limit)
    {
        int n = nums.size();
        vector<int> diff(2 * limit + 2, 0);

        for (int i=0;i<n/2;++i)
        {
            int a = nums[i];
            int b = nums[n - 1 - i];

            diff[2] += 2;
            diff[2 * limit + 1] -= 2;

            int low = min(a, b) + 1;
            int high = max(a, b) + limit;
            diff[low] -= 1;
            diff[high + 1] += 1;
            diff[a + b] -= 1;
            diff[a + b + 1] += 1;
        }

        int ans = n;
        int currentMoves = 0;
        for (int s=2;s<=2*limit;++s)
        {
            currentMoves += diff[s];
            ans = min(ans, currentMoves);
        }

        return ans;
    }
};
