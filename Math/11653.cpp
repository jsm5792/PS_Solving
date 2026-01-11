#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int index = 2;
    while(N!=1)
    {
        if(N%index==0)
        {
            cout << index <<'\n';
            N/= index;
        }
        else
        {
            index++;
        }

    }
}
