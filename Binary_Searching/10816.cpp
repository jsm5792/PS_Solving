#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int a[500005];
int N,M;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
    }
    sort(a,a+N);
    cin >> M;
    while(M--)
    {
        int b;
        cin >> b;
        cout << upper_bound(a,a+N,b) - lower_bound(a,a+N,b) <<'\n';
    }

}
