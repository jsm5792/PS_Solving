#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,K;
int vis[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    fill(vis,vis+100005,-1);
    queue<int> q;
    q.push(N);
    bool found = false;
    if(N==K)
    {
        cout << "0\n" << N;
        return 0;
    }
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(int i=0;i<3;i++)
        {
            if(i==1)
            {
                int next = curr -1;
                if(next<0 || next > 100000)
                {
                    continue;
                }
                if(vis[next]!=-1)
                {
                    continue;
                }
                vis[next] = curr;
                if(next == K)
                {
                    found = true;
                    break;
                }
                q.push(next);
            }
            else if(i==2)
            {
                int next = curr + 1;
                if(next<0 || next > 100000)
                {
                    continue;
                }
                if(vis[next]!=-1)
                {
                    continue;
                }
                vis[next] = curr;
                if(next == K)
                {
                    found = true;
                    break;
                }
                q.push(next);

            }
            else
            {
                int next = curr * 2;
                if(next<0 || next > 100000)
                {
                    continue;
                }
                if(vis[next]!=-1)
                {
                    continue;
                }
                vis[next] = curr;
                if(next == K)
                {
                    found = true;
                    break;
                }
                q.push(next);
            }
        }
        if(found)
        {
            break;
        }
    }
    stack<int> s;
    s.push(K);
    int temp = K;
    while(1)
    {
        temp = vis[temp];
        s.push(temp);
        if(temp == N)
        {
            break;
        }
    }
    cout << s.size() -1 <<'\n';
    while(!s.empty())
    {
        cout << s.top()<<' ';
        s.pop();
    }
}
