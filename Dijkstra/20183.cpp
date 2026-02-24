#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M,A,B;
long long C;
vector<pair<int,int>> v[100005];
long long d[100005];

bool check(long long a)
{
    fill(d,d+N+1,1e15);
    priority_queue <pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    d[A] = 0;
    pq.push({0,A});
    while(!pq.empty())
    {
        long long x = pq.top().first;
        int y = pq.top().second;
        pq.pop();
        if(d[y] != x)
        {
            continue;
        }
        if(y == B)
        {
            break;
        }
        for(auto next: v[y])
        {
            long long x1 = next.first;
            long long y1 = next.second;
            if(x1 > a)
            {
                continue;
            }
            if(d[y1] > x1 + x)
            {
                d[y1] = x1 + x;
                pq.push({d[y1],y1});
            }
        }
    }
    return d[B] <= C;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> A >> B >> C;   
    for(int i=0;i<M;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        v[x].push_back({z,y});
        v[y].push_back({z,x});
    }
    long long st = 1;
    long long ed = 1e9;
    long long ans = -1;
    while(st <= ed)
    {
        long long mid = (st + ed) / 2;
        if(check(mid))
        {
            ans = mid;
            ed = mid -1;
        }
        else
        {
            st = mid + 1;
        }
    }
    cout << ans;
}
