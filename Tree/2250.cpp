#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,max_height,x_pos,height;
pair<int,int> p[10005];
int min_a[10005];
int max_a[10005];
bool child[10005];

void DFS(int curr)
{
    if(p[curr].first != -1)
    {
        height++;
        DFS(p[curr].first);
        height--;
    }
    min_a[height] = min(min_a[height],x_pos);
    max_a[height] = max(max_a[height],x_pos);
    max_height = max(max_height, height);
    x_pos++;
    if(p[curr].second != -1)
    {
        height++;
        DFS(p[curr].second);
        height--;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        p[x] = {y,z};
        if(y!=-1)
        {
            child[y] = true;
        }
        if(z!=-1)
        {
            child[z] = true;
        }
    }
    int root = 1;
    for(int i=1;i<=N;i++)
    {
        if(!child[i])
        {
            root = i;
            break;
        }
    }
    fill(min_a,min_a+N+1,999999);
    x_pos = 1;
    height = 1;
    DFS(root);
    int ans_width = 0;
    int ans_level = 1;

    for(int i=1;i<=max_height;i++)
    {
        int width = max_a[i] - min_a[i] + 1;
        if(width > ans_width)
        {
            ans_width = width;
            ans_level = i;
        }
    }
    cout << ans_level << " " << ans_width;
}
