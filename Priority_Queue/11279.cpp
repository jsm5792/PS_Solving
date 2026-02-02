#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue <int> pq;
    cin >> N;
    while(N--)
    {
        int x;
        cin >> x;
        if(x==0)
        {
            if(pq.empty())
            {
                cout <<"0\n";
            }
            else
            {
                cout << pq.top()<<'\n';
                pq.pop();
            }
        }
        else
        {
            pq.push(x);
        }
    }
}
