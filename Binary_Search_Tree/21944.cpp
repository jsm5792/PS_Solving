#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,L,P,G,X;
pair<int,int> p[100005];
set<int> s1[105];
set<int> s2[105][105];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while(N--)
    {
        cin >> P >> L >> G;
        p[P] = {L,G};
        s1[L].insert(P);
        s2[G][L].insert(P);
    }
    cin >> N;
    while(N--)
    {
        string s;
        cin >> s;
        if(s == "recommend")
        {
            cin >> G >> X;
            if(X == 1)
            {
                for(int i=100;i>=0;i--)
                {
                    if(s2[G][i].empty())
                    {
                        continue;
                    }
                    cout << *(prev(s2[G][i].end())) <<'\n';
                    break;
                }
            }
            else
            {
                for(int i=0;i<=100;i++)
                {
                    if(s2[G][i].empty())
                    {
                        continue;
                    }
                    cout << *s2[G][i].begin() << '\n';
                    break;
                }
            }
        }
        else if(s == "recommend2")
        {
            cin >> X;
            if(X==1)
            {
                for(int i=100;i>=0;i--)
                {
                    if(s1[i].empty())
                    {
                        continue;
                    }
                    cout << *(prev(s1[i].end())) << '\n';
                    break;
                }
            }
            else
            {
                for(int i=0;i<=100;i++)
                {
                    if(s1[i].empty())
                    {
                        continue;
                    }
                    cout << *s1[i].begin() <<'\n';
                    break;
                }
            }
        }
        else if(s == "recommend3")
        {
            cin >> X >> L;
            int ans = -1;
            if(X==1)
            {
                for(int i=L;i<=100;i++)
                {
                    if(s1[i].empty())
                    {
                        continue;
                    }
                    ans = *s1[i].begin();
                    break;
                }
            }
            else
            {
                for(int i=L-1;i>=0;i--)
                {
                    if(s1[i].empty())
                    {
                        continue;
                    }
                    ans = *(prev(s1[i].end()));
                    break;
                }
            }
            cout << ans << '\n';
        }
        else if(s == "add")
        {
            cin >> P >> L >> G;
            p[P] = {L,G};
            s1[L].insert(P);
            s2[G][L].insert(P);
        }
        else
        {
            cin >> P;
            L = p[P].first;
            G = p[P].second;
            s1[L].erase(P);
            s2[G][L].erase(P);
        }
    }

}
