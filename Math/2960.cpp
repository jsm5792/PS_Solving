#include <iostream>
#include <bits/stdc++.h>

using namespace std;
bool a[1000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,K;
    cin >> N >> K;
    int count=0;
    int index=2;
    while(1)
    {
        for(int i=1;i<=N/index;i++)
        {
            if(a[i*index]==false)
            {
                a[i*index]=true;
                count++;                
            }
            if(count==K)
            {
                cout << i*index;
                return 0;
            }
        }
        index++;
    }
}
