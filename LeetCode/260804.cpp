
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        bool a[105] = {};
        int x = nums[0];
        int y = nums[0];
        for(int i=0;i<nums.size();i++)
        {
            a[nums[i]] = true;
            x = max(x,nums[i]);
            y = min(y,nums[i]);
        }
        for(int i=y;i<=x;i++)
        {
            if(a[i]==false)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
