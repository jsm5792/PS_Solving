#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int N;
long long ans;
set<int> s;
int a[250005];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    s.insert(0);
    s.insert(N+1);
    
    int temp;
    cin >> temp;
    temp++;
    a[temp] = 1;
    s.insert(temp);
    ans = 1;
    N--;

    for(int i=0;i<N;i++)
    {
        cin >> temp;
        temp++;
        auto it = s.lower_bound(temp);
        a[temp] = max(a[*prev(it)],a[*it])+1;
        s.insert(temp);
        ans += a[temp];
    }
    cout << ans;
}
