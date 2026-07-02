#include <bits/stdc++.h>
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        queue<tuple<int,int,int>> q;

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> max_health(m, vector<int>(n, -1));
        max_health[0][0] = health - grid[0][0];
        q.push({0,0,health-grid[0][0]});
        while(!q.empty())
        {
            int x,y,h;
            tie(x,y,h) = q.front();
            q.pop();
            if(x == m-1 && y == n-1 && h >= 1)
            {
                return true;
            }
            if(h < max_health[x][y])
            {
                continue;
            }
            for(int i=0;i<4;i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= m || nx < 0 || ny >= n || ny<0)
                {
                    continue;
                }
                int nh = h - grid[nx][ny];
                if(nh >= 1 && nh > max_health[nx][ny])
                {
                    max_health[nx][ny] = nh;
                    q.push({nx,ny,nh});
                }
            }
        }
        return false;
    }
};
