#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;
int a[13];
int b[13];
bool c[13];

void solve(int x)
{
    if(x==M)
    {
        for(int i=0;i<M;i++)
        {
            cout << b[i] << ' ';
        }
        cout <<'\n';
        return;
    }
    int temp = 0;
    for(int i=0;i<N;i++)
    {
        if(c[i]==false && temp != a[i])
        {
            c[i] = true;
            b[x] = a[i];
            temp = b[x];
            solve(x+1);
            c[i] = false;
        }
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
    }
    sort(a,a+N);
    solve(0);
}
