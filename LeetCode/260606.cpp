class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int tot = 0;
        int left = 0;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            tot += nums[i];
        }
        for(int i=0;i<n;i++)
        {
            int right = tot - left - nums[i];
            ans.push_back(abs(left-right));
            left += nums[i];
        }
        return ans;
    }
};
