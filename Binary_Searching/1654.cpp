#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int K,N;
int a[10005];

bool fine(long long x)
{
    long long y = 0;
    for(int i=0;i<K;i++)
    {
        y += a[i] / x;
    }
    if(y>=N)
    {
        return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> K >> N;
    for(int i=0;i<K;i++)
    {
        cin >> a[i];
    }
    long long start = 1;
    long long end = INT_MAX;
    while(start < end)
    {
        long long mid = (start + end+1)/2;
        if(fine(mid))
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
