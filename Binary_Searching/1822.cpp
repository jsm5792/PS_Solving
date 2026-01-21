#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int a[500005];
int b[500005];
int A,B;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v;

    cin >> A >> B;
    for(int i=0;i<A;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<B;i++)
    {
        cin >> b[i];
    }
    sort(a,a+A);
    sort(b,b+B);
    for(int i=0;i<A;i++)
    {
        if(!binary_search(b,b+B,a[i]))
        {
            v.push_back(a[i]);            
        }
    }
    cout << v.size() <<'\n';
    for(int i=0;i<v.size();i++)
    {
        cout << v[i] <<' ';
    }
}
