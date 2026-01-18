#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    vector<int> v;
    if(N==0)
    {
        cout <<0;
        return 0;
    }
    while(N)
    {
        if(N<0)
        {
            if(-N%2==0)
            {
                N = -N/2;
                v.push_back(0);
            }
            else
            {
                N= -N/2+1;
                v.push_back(1);
            }
        }
        else
        {
            v.push_back(N%2);
            N = -(N/2);
        }
    }
    for(int i=v.size()-1;i>=0;i--)
    {
        cout <<v[i];
    }
}
