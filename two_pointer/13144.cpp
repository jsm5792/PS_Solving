#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int N;
int a[100005];
bool b[100005];
long long ans;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
    }
    int end = 0;
    for(int start=0;start<N;start++)
    {
        while(end<N && !b[a[end]])
        {
            b[a[end]] = true;
            end++;
        }
        ans += (end - start);
        b[a[start]] = false;
    }
    cout << ans;
    
}
