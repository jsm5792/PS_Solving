#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int T;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--)
    {
        int a;
        cin >> a;
        multiset<int> m;
        while(a--)
        {
            char b;
            cin >> b;
            if(b=='D')
            {
                int c;
                cin >> c;
                if(m.empty())
                {
                    continue;
                }
                if(c==1)
                {
                    m.erase(prev(m.end()));
                }
                else
                {
                    m.erase(m.begin());
                }
            }
            else
            {
                int c;
                cin >> c;
                m.insert(c);
            }
        }
        if(m.empty())
        {
            cout << "EMPTY\n";
        }
        else
        {
            cout << *prev(m.end()) <<' '<< *m.begin() <<'\n';
        }
    }
}
