#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int a[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
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
        cout << binary_search(a,a+N,b)<<'\n';
    }

}
