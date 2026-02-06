#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
int a[105][105];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> a[i][j];
        }
    }
    for(int k=0;k<N;k++)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(a[i][k]==1 && a[k][j]==1)
                {
                    a[i][j]=1;
                }
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout << a[i][j] <<' ';
        }
        cout << '\n';
    }
}
