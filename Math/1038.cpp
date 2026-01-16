#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long ans(int x)
{
    vector <long long> v;
    for(int i=1;i<1024;i++)
    {
        int a = i;
        long long num = 0;
        for(int j=9;j>=0;j--)
        {
            if(a%2==1)
            {
                num = num*10 + j;
            }
            a /= 2;
        }
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    if(x>1022)
    {
        return -1;
    }
    return v[x];

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    cout << ans(N);
}
