#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;
int a[10005];

bool solve(int x)
{
    long long sum = 0;
    for(int i=0;i<N;i++)
    {
        if(a[i]<=x)
        {
            sum+=a[i];
        }
        else
        {
            sum+=x;
        }
    }
    return M>=sum;

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
    }
    cin >> M;
    sort(a,a+N);
    int start = 0;
    int end = a[N-1];
    while(start<end)
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
