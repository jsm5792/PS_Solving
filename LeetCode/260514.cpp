class Solution {
public:
    bool isGood(vector<int>& nums) {
        int check[105] = {};
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i] > n-1)
            {
                return false;
            }
            check[nums[i]]++;
            if(check[nums[i]] > 1 & nums[i] != n-1)
            {
                return false;
            }
            if(nums[i]==n-1 && check[nums[i]]>2)
            {
                return false;
            }

        }
        return true;
    }
};
