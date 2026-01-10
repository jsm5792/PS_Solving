#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int a=0;
    int b=0;
    char temp = s[0];
    for(auto i : s)
    {
        if(i != temp)
        {
            if(temp =='0')
            {
                a++;
            }
            else
            {
                b++;
            }
            temp = i;
        }
    }
    if(temp =='0')
    {
        a++;
    }
    else
    {
        b++;
    }
    cout << min(a,b);
}
