#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x;
    cin >> x;
    int index=1;
    while(index*(index+1)/2 < x)
    {
        index++;
    }
    int p,q,r;
    r=(index * (index+1) /2 )- x;
    if(index%2==1)
    {
        p = 1 +r;
        q = index - r;        
    }
    else
    {
        p = index - r;
        q = 1 + r;
    }
    cout << p <<'/' <<q;
}
