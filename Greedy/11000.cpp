#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    deque <int> q1,q2;
    for(int i=0;i<N;i++)
    {
        int start, end;
        cin >> start >> end;
        q1.push_back(start);
        q2.push_back(end);
    }
    sort(q1.begin(),q1.end());
    sort(q2.begin(),q2.end());
    int ans = 0;
    int temp = 0;
    while(!q1.empty())
    {
        if(q1.front() < q2.front())
        {
            temp ++;
            q1.pop_front();
        }
        else if(q1.front() == q2.front())
        {
            q1.pop_front();
            q2.pop_front();
        }
        else
        
        {
            temp--;
            q2.pop_front();
        }
        ans = max(ans,temp);
    }
    cout << ans;
}
