#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int a[1000005];
int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector <int> v;
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=0;i<N;i++)
    {
        cout << lower_bound(v.begin(),v.end(),a[i]) - v.begin() << ' ';
    }
}
