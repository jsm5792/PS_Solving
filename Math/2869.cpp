#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b,v;
    cin >> a >> b >> v;
    int i;
    if(a >= v)
    {
        cout << 1;
        return 0;
    }
    i = (v-b)/(a-b);
    if((v-b)%(a-b)!=0)
    {
        i++;
    }
    cout << i;
}