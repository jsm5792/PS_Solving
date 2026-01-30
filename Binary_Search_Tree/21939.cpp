#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int N,M;
int a[100005];
set<int> b[105];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        int x,y;
        cin >> x >> y;
        a[x] = y;
        b[y].insert(x);
    }
    cin >> M;
    while(M--)
    {
        string s;
        cin >> s;
        if(s=="recommend")
        {
            int x;
            cin >> x;
            if(x == 1)
            {
                for(int i=100;i>=0;i--)
                {
                    if(b[i].empty())
                    {
                        continue;
                    }
                    cout << *b[i].rbegin() <<'\n';
                    break;
                }
            }
            else
            {
                for(int i=0;i<101;i++)
                {
                    if(b[i].empty())
                    {
                        continue;
                    }
                    cout << *b[i].begin() << '\n';
                    break;
                }
            }
        }
        else if(s=="add")
        {
            int x,y;
            cin >> x >> y;
            a[x] = y;
            b[y].insert(x);
        }
        else
        {
            int x;
            cin >> x;
            b[a[x]].erase(x);
        }
    }
}
