#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long num(long long n, int p)
{
    long long ans = 0;
    long long div = p;
    while(n/div)
    {
        ans += (n/div);
        div *= p;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n,m;
    cin >> n >> m;
    long long two = num(n,2) - num(m,2) - num(n-m,2);
    long long five = num(n,5) - num(m,5) - num(n-m,5);
    cout << min(two,five);

}
