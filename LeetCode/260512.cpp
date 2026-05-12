bool compare(vector<int> a, vector<int> b)
{
    return(a[1]-a[0]) > (b[1]-b[0]);
}

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),compare);
        int curr = 0;
        int initial = 0;
        for(auto i : tasks)
        {
            int x = i[0];
            int y = i[1];
            if(curr < y)
            {
                initial += (y - curr);
                curr = y;
            }
            curr -= x;
        }
        return initial;
    }
};
