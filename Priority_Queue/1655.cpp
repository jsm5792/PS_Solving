#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    priority_queue <int> max_pq;
    priority_queue <int, vector<int>, greater<int>> min_pq;
    for(int i=0;i<N;i++)
    {
        int temp;
        cin >> temp;
        if(max_pq.size() == min_pq.size())
        {
            max_pq.push(temp);
        }
        else
        {
            min_pq.push(temp);
        }
        if(!min_pq.empty() && max_pq.top() > min_pq.top())
        {
            int max_top = max_pq.top();
            int min_top = min_pq.top();
            max_pq.pop();
            min_pq.pop();
            max_pq.push(min_top);
            min_pq.push(max_top);
        }
        cout << max_pq.top() << '\n';

    }
}
