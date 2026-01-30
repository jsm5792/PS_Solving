#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int N,Q;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    set <int> s;
    cin >> N >> Q;
    for(int i=1;i<=N;i++)
    {
        int a;
        cin >> a;
        if(a==1)
        {
            s.insert(i);
        }
    }
    int curr = 1;
    while(Q--)
    {
        int x,y;
        cin >> x;
        if(x==3)
        {
            if(s.empty())
            {
                cout << -1 <<'\n';
            }            
            else
            {
                auto it = s.lower_bound(curr);
                if(it != s.end())
                {
                    cout << *it - curr << '\n';
                }
                else
                {
                    cout << N-curr + *s.begin() << '\n';
                }
            }
        }
        else if(x==2)
        {
            cin >> y;
            curr = (curr + y -1)% N +1;
        }
        else
        {
            cin >> y;
            if(s.find(y)!=s.end())
            {
                s.erase(y);
            }
            else
            {
                s.insert(y);
            }
        }
    }
}
