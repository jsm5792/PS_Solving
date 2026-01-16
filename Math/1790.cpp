#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long k;
    cin >> n >> k;
    long long len = 1;
    long long exp = 1;
    while(k > 9LL*len*exp)
    {
        k -= 9LL*len*exp;
        len++;
        exp*=10;
    }
    int a = exp + (k-1)/len;
    if(a>n)
    {
        cout<<-1;
        return 0;
    }
    cout << to_string(a)[(k-1)%len];
}
