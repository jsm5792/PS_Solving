#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long N;
int dice[6];
int a,b,c;
vector<long long> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<6;i++)
    {
        cin >> dice[i];
    }
    a = min(dice[0],dice[5]);
    b = min(dice[1],dice[4]);
    c = min(dice[2],dice[3]);
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    sort(v.begin(),v.end());
    if(N>1)
    {
        long long v1 = v[0];
        long long v2 = v[0] + v[1];
        long long v3 = v[0] + v[1] + v[2];
        long long s3 = 4;
        long long s2 = 4 * (N-1) + 4 * (N-2);
        long long s1 = 4 * (N-1) * (N-2) + (N-2) * (N-2);
        cout << v1 * s1 + v2 * s2 + v3 * s3;
    }
    else
    {
        long long ans = 0;
        sort(dice,dice+6);
        for(int i=0;i<5;i++)
        {
            ans += dice[i];
        }
        cout << ans;
    }
    

}
