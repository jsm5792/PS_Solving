#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int sum(int n)
{
    int i=1;
    int ans=0;
    while(n>i)
    {
        ans += i*i;
        n -= i;
        i++;
    }
    return ans + i*n;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int A,B;
    cin >> A >> B;
    cout << sum(B) - sum(A-1);
}
