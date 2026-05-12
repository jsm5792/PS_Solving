class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        stack<int> s;
        for(int i=0;i<nums.size();i++)
        {
            int index = nums[i];
            while(index >= 10)
            {
                s.push(index % 10);
                index /= 10;
            }
            ans.push_back(index);
            while(!s.empty())
            {
                ans.push_back(s.top());
                s.pop();
            }
        }
        return ans;
    }
};
