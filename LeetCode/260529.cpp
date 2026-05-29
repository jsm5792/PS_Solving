int DigitSum(int n)
{
    int ans = 0;
    while(n>9)
    {
        ans += n%10;
        n/= 10;
    }
    ans += n;
    return ans;
}

class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = 1e9;
        for(int i=0;i<nums.size();i++)
        {
            ans = min(ans,DigitSum(nums[i]));
        }
        return ans;
    }
};
