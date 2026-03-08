#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool check[5000005];
int nxt[5000005][26];
int a = 2;
int N,M;

int c_to_i(char c)
{
    return c - 'a';
}

void insert(string s)
{
    int curr = 1;
    for(auto c : s)
    {
        if(nxt[curr][c_to_i(c)] == -1)
        {
            nxt[curr][c_to_i(c)] = a++;
        }
        curr = nxt[curr][c_to_i(c)];
    }
    check[curr] = true;
}

bool find(string s)
{
    int curr = 1;
    for(auto c : s)
    {
        if(nxt[curr][c_to_i(c)] == -1)
        {
            return false;
        }
        curr = nxt[curr][c_to_i(c)];
    }
    return check[curr];
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<5000005;i++)
    {
        fill(nxt[i],nxt[i]+26,-1);
    }
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        string s;
        cin >> s;
        insert(s);
    }
    int ans = 0;
    for(int i=0;i<M;i++)
    {
        string s;
        cin >> s;
        ans += find(s);
    }
    cout << ans;
}
