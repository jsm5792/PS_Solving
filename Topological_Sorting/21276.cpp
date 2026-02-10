#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;
string name[1005];
vector <int> v[1005];
vector <int> anc[1005];
int indegree[1005];
unordered_map <string,int> m;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        cin >> name[i];
    }
    sort(name+1,name+N+1);
    for(int i=1;i<=N;i++)
    {
        m[name[i]]=i;
    }
    cin >> M;
    for(int i=0;i<M;i++)
    {
        string x,y;
        cin >> x >> y;
        v[m[y]].push_back(m[x]);
        indegree[m[x]]++;
    }

    vector<int> v1;
    for(int i=1;i<=N;i++)
    {
        if(indegree[i]==0)
        {
            v1.push_back(i);
        }
    }
    for(int i=1;i<=N;i++)
    {
        sort(v[i].begin(),v[i].end());
        for(auto next : v[i])
        {
            if(indegree[next]-indegree[i]==1)
            {
                anc[i].push_back(next);
            }
        }
    }
    cout << v1.size() <<'\n';
    for(auto i : v1)
    {
        cout << name[i] << ' ';
    }
    cout << '\n';
    for(int i=1;i<=N;i++)
    {
        int cnt = anc[i].size();
        cout << name[i] << ' ' << cnt <<' ';
        for(auto j : anc[i])
        {
            cout << name[j] << ' ';
        }
        cout << '\n';
    }

}
