#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int M,N;
int a[1000005];

bool solve(int x)
{
    if(x==0)
    {
        return true;
    }
    long long y=0;
    for(int i=0;i<N;i++)
    {
        y+= a[i]/x;
    }
    if(y >= M)
    {
        return true;
    }
    return false;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N;
    int end=0;
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
        end = max(a[i],end);
    }
    int start = 0;
    while(start < end)
    {
        int mid = (start+end+1)/2;
        if(solve(mid))
        {
            start = mid;
        }
        else
        {
            end = mid-1;
        }
    }
    cout << start;
}
