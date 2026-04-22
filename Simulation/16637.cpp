#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
string s;
long long ans = -2e18;

long long calculate(long long a, long long b, char op)
{
    if(op=='+') return a + b;
    if(op=='-') return a - b;
    if(op=='*') return a * b;
    return 0;
}

void solve(int idx, long long cur)
{
    if(idx>=N)
    {
        ans = max(ans, cur);
        return;
    }

    char op = (idx==0) ? '+' : s[idx - 1];

    if(idx+2<N)
    {
        long long bracket = calculate(s[idx] - '0', s[idx + 2] - '0', s[idx + 1]);
        solve(idx + 4, calculate(cur, bracket, op));
    }

    solve(idx + 2, calculate(cur, s[idx] - '0', op));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> s;

    solve(0, 0);

    cout << ans;

}
