#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;
bool isprime[10005];

void prime()
{
    for(int i=2;i<10000;i++)
    {
        isprime[i] = true;
    }
    for(int i=2;i*i<10000;i++)
    {
        for(int j=i*i;j<10000;j+=i)
        {
            if(isprime[j])
            {
                isprime[j]=false;
            }
        }
    }
}

void move(int N,int M)
{
    queue <int> q;
    q.push(N);
    int visit[10005];
    for(int i=1000;i<10000;i++)
    {
        visit[i] = -1;
    }
    visit[N] = 0;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        if(curr == M)
        {
            cout << visit[M] << '\n';
            return;
        }
        string s = to_string(curr);
        for(int i=0;i<=3;i++)
        {
            string temp = s;
            for(int j=0;j<=9;j++)
            {
                if(i==0 && j==0)
                {
                    continue;
                }
                temp[i] = j+'0';
                int next = stoi(temp);
                if(isprime[next] && visit[next]==-1)
                {
                    visit[next] = visit[curr]+1;
                    q.push(next);
                }
            }
        }

    }
    cout << "Impossible"<<'\n';
    return;
}




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    prime();
    while(T--)
    {
        int N,M;
        cin >> N >> M;
        move(N,M);
    }
}
