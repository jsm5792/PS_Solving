#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v[100005];
int a[100005];

void DFS(int curr)
{
    for(auto next : v[curr])
    {
        if(a[curr] == next)
        {
            continue;
        }
        a[next] = curr;
        DFS(next);
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N-1;i++)
    {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS(1);
    for(int i=2;i<=N;i++)
    {
        cout << a[i] <<'\n';
    }
}
