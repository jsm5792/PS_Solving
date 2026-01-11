#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int N;
int a[1000005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        int num;
        cin >> num;
        a[num] = i;
    }
    int len=0;
    int cur=1;
    for(int i=1;i<=N;i++)
    {
        if(a[i]<a[i+1])
        {
            cur++;
        }
        else
        {
            len = max(len,cur);
            cur = 1;
        }
    }
    len = max(len,cur);
    cout << N-len;
}
