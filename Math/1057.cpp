#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,x,y;
    cin >> N >> x >> y;
    x--;
    y--;
    int count = 1;
    while(x/2 != y/2)
    {
        x /= 2;
        y /= 2;
        count++;
    }
    cout << count;
}
