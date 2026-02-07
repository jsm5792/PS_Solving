#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
int L[30];
int R[30];

void pre(int curr)
{
    cout << char(curr+'A'-1);
    if(L[curr] != 0)
    {
        pre(L[curr]);
    }
    if(R[curr] != 0)
    {
        pre(R[curr]);
    }
}

void in(int curr)
{
    if(L[curr] != 0)
    {
        in(L[curr]);
    }
    cout << char(curr+'A'-1);
    if(R[curr] != 0)
    {
        in(R[curr]);
    }
}

void post(int curr)
{
    if(L[curr] != 0)
    {
        post(L[curr]);
    } 
    if(R[curr] != 0)
    {
        post(R[curr]);
    }
    cout << char(curr+'A'-1);

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        char a,b,c;
        cin >> a >> b >> c;
        if(b != '.')
        {
            L[a-'A'+1] = b-'A'+1;
        }
        if(c != '.')
        {
            R[a-'A'+1] = c-'A'+1;
        }
    }
    pre(1);
    cout <<'\n';
    in(1);
    cout <<'\n';
    post(1);
}
