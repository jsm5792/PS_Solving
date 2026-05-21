int digit(int x)
{
    int count = 0;
    while(x>0)
    {
        count++;
        x /= 10;
    }
    return count;
}

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> pre;
        for(int i : arr1)
        {
            int x = i;
            while(x>0)
            {
                pre.insert(x);
                x/=10;
            }
        }
        int ans = 0;
        for(int i : arr2)
        {
            int x = i;
            int len = digit(i);
            while(x>0)
            {
                if(pre.count(x))
                {
                    ans = max(ans,len);
                    break;
                }
                x/=10;
                len--;
            }
        }
        return ans;
    }
};
