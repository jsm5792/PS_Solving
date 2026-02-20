#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;
vector<int> v(10);
vector<int> ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> v[i];
    }
    cin >> M;
    int a = 100;
    int b = 0;
    int c = 100;
    int d = 0;
    for(int i=0;i<N;i++)
    {
        if(v[i] <= a)
        {
            a = v[i];
            b = i;
        }        
    }
    for(int i=1;i<N;i++)
    {
        if(v[i] <= c)
        {
            c = v[i];
            d = i;
        }
    }
    if(M < c)
    {
        cout << 0;
        return 0;
    }
    ans.push_back(d);
    M-= c;
    
    while(M >= a)
    {
        ans.push_back(b);
        M -= a;
    }
    for(int i=0;i<ans.size();i++)
    {
        for(int j=N-1;j>ans[i];j--)
        {
            int diff = v[j] - v[ans[i]];
            if(M >= diff)
            {
                M-= diff;
                ans[i] = j;
                break;
            } 
        }
    }
    for(auto i : ans)
    {
        cout << i;
    }

}
