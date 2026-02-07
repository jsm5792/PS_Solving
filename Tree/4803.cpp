#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M,T,ans;
vector<int> v[505];
bool vis[505];
bool check;

void DFS(int curr,int prev)
{
    for(auto next : v[curr])
    {
        if(next == prev)
        {
            continue;
        }
        if(vis[next])
        {
            check = false;
            continue;
        }
        vis[next] = true;
        DFS(next,curr);
    }
}




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    T =1;
    while(1)
    {
        cin >> N >> M;
        if(N==0 && M==0)
        {
            break;
        }
        fill(vis,vis+N+1,false);
        for(int i=1;i<=N;i++)
        {
            v[i].clear();
        }
        ans = 0;
        while(M--)
        {
            int x,y;
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        for(int i=1;i<=N;i++)
        {
            if(vis[i])
            {
                continue;
            }
            vis[i] = true;
            check = true;
            DFS(i,-1);
            ans += check;
        }
        cout << "Case "<<T<<": ";
        T++;
        if(ans==0)
        {
            cout << "No trees.\n";
        }
        else if(ans==1)
        {
            cout << "There is one tree.\n";
        }
        else
        {
            cout << "A forest of "<<ans<<" trees.\n";
        }


    }
}
