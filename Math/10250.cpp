#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        int H,W,N;
        cin >> H >> W >> N;
        int a,b;
        a = N%H;
        b = (N+H-1)/H;
        if(b>9)
        {
            cout <<a<<b<<'\n';
        }
        else
        {
            cout<< a<<'0'<<b<<'\n';
        }
    }
}
