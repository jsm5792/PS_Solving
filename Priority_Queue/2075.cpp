#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue <int,vector<int>,greater<int>> pq;
    cin >> N;
    for(int i=0;i<N*N;i++)
    {
        int x;
        cin >> x;
        pq.push(x);
        if(N < pq.size())
        {
            pq.pop();
        }
    }
    cout << pq.top();
}
