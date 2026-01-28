#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string S,E,Q;
int s_t, e_t, q_t;

void time_convert()
{
    s_t = int(S[0]) * 1000 + int(S[1]) * 100 + int(S[3]) *10 + int(S[4]);
    e_t = int(E[0]) * 1000 + int(E[1]) * 100 + int(E[3]) *10 + int(E[4]);
    q_t = int(Q[0]) * 1000 + int(Q[1]) * 100 + int(Q[3]) *10 + int(Q[4]);

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> S >> E >> Q;
    time_convert();
    unordered_set <string> start;
    unordered_set <string> end;
    string a,b;
    while(cin >> a >> b)
    {
        int a_time = int(a[0]) * 1000 + int(a[1]) * 100 + int(a[3]) * 10 + int(a[4]);
        if(a_time <= s_t)
        {
            start.insert(b);
        }
        else if(a_time >= e_t && a_time <= q_t)
        {
            if(start.find(b)!=start.end())
            {
                
                end.insert(b);
            }
        }
    }
    cout << end.size();
    
}
