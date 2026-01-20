#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
int a[10005];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector <int> v;
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
    }
    
    sort(a,a+N);
    
    for(int i=0;i<N;i++)
    {
        for(int j=i;j<N;j++)
        {
            v.push_back(a[i]+a[j]);
        }
    }
    
    sort(v.begin(),v.end());

    for(int i=N-1;i>=0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(binary_search(v.begin(),v.end(),a[i]-a[j]))
            {
                cout << a[i];
                return 0;
            }
        }
    }

}
