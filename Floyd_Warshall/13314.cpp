#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << 100 <<'\n';
    for(int i=1;i<=100;i++)
    {
        for(int j=1;j<=100;j++)
        {
            if(i==j)
            {
                cout <<"0 ";
            }
            else if(i==100 || j==100)
            {
                cout << "1 ";
            }
            else
            {
                cout <<"100 ";
            }
        }
        cout <<'\n';
    }
}
