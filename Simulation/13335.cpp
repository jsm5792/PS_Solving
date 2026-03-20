#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,W,L;
int weight[1005];
int t[1005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> W >> L;
    for(int i=0;i<N;i++)
    {
        cin >> weight[i];
    }
    t[0] = 1;
    int sum = weight[0];
    int curr = 0;
    for(int i=1;i<N;i++)
    {
        while(i - curr + 1 > W || sum + weight[i] > L)
        {
            sum -= weight[curr];
            curr++;
        }
        sum += weight[i];
        if(curr == 0)
        {
            t[i] = t[i-1] + 1;
        }
        else
        {
            t[i] = max(t[i-1] + 1, t[curr-1] + W);
        }
    }
    cout << t[N-1] + W;
}
