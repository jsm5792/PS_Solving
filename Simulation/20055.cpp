#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N, K;
int A[205];
bool robot[105];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for(int i=1;i<=2*N;i++)
    {
        cin >> A[i];
    }
    int step = 0;
    while(1)
    {
        step++;
        int last_a = A[2 * N];
        for(int i=2*N;i>1;i--)
        {
            A[i] = A[i - 1];
        }
        A[1] = last_a;
        for(int i=N;i>1;i--)
        {
            robot[i] = robot[i - 1];
        }
        robot[1] = false;
        robot[N] = false;
        for(int i=N-1;i>1;i--)
        {
            if(robot[i]&&!robot[i+1]&&A[i+1]>=1)
            {
                robot[i+1] = true;
                robot[i] = false;
                A[i+1]--;
            }
        }
        robot[N] = false;
        if(!robot[1]&&A[1]>0)
        {
            robot[1] = true;
            A[1]--;
        }
        int cnt = 0;
        for(int i=1;i<=2*N;i++)
        {
            if(A[i]==0)
            {
                cnt++;
            }
        }
        if(cnt>=K)
        {
            break;
        }
    }
    cout << step;
}
