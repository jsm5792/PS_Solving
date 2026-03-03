#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
int a[15];
int b[6];

void solve(int x,int y)
{
    if(x==6)
    {
        for(int i=0;i<6;i++)
        {
            cout << b[i] <<' ';
        }
        cout <<'\n';
        return;
    }
    for(int i=y;i<N;i++)
    {
        b[x] = a[i];
        solve(x+1,i+1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1)
    {
        cin >> N;
        if(N==0)
        {
            break;
        }
        vector<int> v;
        for(int i=0;i<N;i++)
        {
            cin >> a[i];
        }
        solve(0,0);
        cout <<'\n';

    }
}
