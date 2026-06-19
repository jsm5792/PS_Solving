class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> v;
        int ans = 0;
        v.push_back(ans);
        for(int i=0;i<gain.size();i++)
        {
            v.push_back(v[i] + gain[i]);
            ans = max(ans,v[i+1]);
        }
        return ans;
    }
};
