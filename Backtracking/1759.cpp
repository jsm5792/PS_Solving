#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int L,C;
char a[16];
char b[16];

void solve(int x,int y)
{
    if(x==L)
    {
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i=0;i<L;i++)
        {
            if(b[i]=='a' || b[i]=='e' || b[i]=='i' || b[i]=='o' || b[i]=='u')
            {
                cnt1++;
            }
            else
            {
                cnt2++;
            }
        }
        if(cnt1>=1 && cnt2>=2)
        {
            for(int i=0;i<L;i++)
            {
                cout << b[i];
            }
            cout<<'\n';
        }
        return;
    }
    for(int i=y;i<C;i++)
    {
        b[x] = a[i];
        solve(x+1,i+1);
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> L >> C;
    for(int i=0;i<C;i++)
    {
        cin >> a[i];
    }
    sort(a,a+C);
    solve(0,0);
}
