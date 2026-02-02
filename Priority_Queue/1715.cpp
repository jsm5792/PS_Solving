#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int N;
long long ans;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<N;i++)
    {
        int temp;
        cin >> temp;
        pq.push(temp);
    }
    while(pq.size()>1)
    {
        int x,y;
        x = pq.top();
        pq.pop();
        y = pq.top();
        pq.pop();
        pq.push(x+y);
        ans += x+y;
    }
    cout << ans;
}
