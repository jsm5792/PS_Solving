#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int i=0;
    while(3*i*(i+1)+1<N)
    {
        i++;
    }
    cout << i+1;
}
