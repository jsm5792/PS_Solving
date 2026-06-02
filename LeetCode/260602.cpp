class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int minLand = 1e9;
        int minWater = 1e9;
        int m = waterStartTime.size();
        for(int i=0;i<n;i++)
        {
            minLand = min(minLand, landStartTime[i]+landDuration[i]);
        }
        for(int i=0;i<m;i++)
        {
            minWater = min(minWater, waterStartTime[i]+waterDuration[i]);
        }
        int ans = 1e9;
        for(int i=0;i<m;i++)
        {
            if(waterStartTime[i] < minLand)
            {
                ans = min(ans, minLand+waterDuration[i]);
            }
            else
            {
                ans = min(ans, waterStartTime[i]+waterDuration[i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(landStartTime[i] < minWater)
            {
                ans = min(ans,minWater+landDuration[i]);
            }
            else
            {
                ans = min(ans, landStartTime[i]+landDuration[i]);
            }
        }
        return ans;
    }
};
