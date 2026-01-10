#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N, K;
int a[105];
bool b[105];
int c, ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    vector<int> v;
    for(int i=0;i<K;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<K;i++)
    {
        if(b[a[i]])
        {
            continue;
        }
        if(c<N)
        {
            b[a[i]] = true;
            v.push_back(a[i]);
            c++;
        }
        if(b[a[i]]==false)
        {
            int change_index = 0;
            int next = 0;
            for(int j=0;j<v.size();j++)
            {
                int temp_index=111;
                for(int k=i;k<K;k++)
                {
                    if(a[k]==v[j])
                    {
                        temp_index = k;
                        break;
                    }
                }
                if(temp_index > next)
                {
                    next = temp_index;
                    change_index = j;
                }
            }
            b[a[i]] = true;
            b[v[change_index]] = false;
            v[change_index] = a[i];
            ans++;
        }
    }
    cout << ans;

}
