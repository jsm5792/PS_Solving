class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue <int> q;
        vector<bool> vis(n,false);
        q.push(start);
        vis[start] = true;
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            if(arr[x]==0)
            {
                return true;
            }
            int x1 = x + arr[x];
            int x2 = x - arr[x];
            if(x1 < n && vis[x1]==false)
            {
                vis[x1] = true;
                q.push(x1);
            }
            if(x2 >= 0 && vis[x2]==false)
            {
                vis[x2] = true;
                q.push(x2);
            }

        }
        return false;
    }
};
