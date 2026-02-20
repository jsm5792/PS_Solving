#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,S;
vector <int> v(55);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> v[i];
    }
    cin >> S;
    for(int i=0;i<N;i++)
    {
        if(S<=0)
        {
            break;
        }
        int max_v = v[i];
        int index = i;
        for(int j=i+1;j<N;j++)
        {
            if(j>i+S)
            {
                break;
            }
            if(v[j] > max_v)
            {
                max_v = v[j];
                index = j;
            }
        }
        for(int j=index;j>i;j--)
        {
            swap(v[j],v[j-1]);
            S--;
        }
    }
    for(int i=0;i<N;i++)
    {
        cout << v[i] << " ";
    }
}
