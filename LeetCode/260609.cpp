class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        long long x = 0;
        long long y = 1e10;
        for(int i=0;i<n;i++)
        {
            x = max(x,(long long)nums[i]);
            y = min(y,(long long)nums[i]);
        }
        return (x - y) * k;
    }
};
