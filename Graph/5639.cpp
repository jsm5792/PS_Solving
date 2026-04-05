#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int tree[10005];

void solve(int s, int e)
{
    if(s >= e) return;
    if(s == e - 1)
    {
        cout << tree[s] << "\n";
        return;
    }

    int idx = s + 1;
    while(idx < e)
    {
        if(tree[s] < tree[idx]) break;
        idx++;
    }

    solve(s + 1, idx);
    solve(idx, e);
    cout << tree[s] << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, i = 0;
    while(cin >> n)
    {
        tree[i++] = n;
    }

    solve(0, i);

}
