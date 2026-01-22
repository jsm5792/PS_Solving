#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int T,N,M;
int a[1005];
int b[1005];
long long ans;
vector <long long> as;
vector <long long> bs;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
    }
    cin >> M;
    for(int i=0;i<M;i++)
    {
        cin >> b[i];
    }

    for(int i=0;i<N;i++)
    {
        long long sum = 0;
        for(int j=i;j<N;j++)
        {
            sum += a[j];
            as.push_back(sum);
        }
    }
    for(int i=0;i<M;i++)
    {
        long long sum = 0;
        for(int j=i;j<M;j++)
        {
            sum += b[j];
            bs.push_back(sum);
        }
    }
    sort(as.begin(),as.end());
    sort(bs.begin(),bs.end());
    int a_start =0;
    int b_start =bs.size()-1;
    while(a_start < as.size() && b_start >= 0)
    {
        if(as[a_start]+bs[b_start]==T)
        {
            long long temp_a = as[a_start];
            long long temp_b = bs[b_start];
            long long count_a = 0;
            long long count_b = 0;
            while(a_start < as.size() && as[a_start] == temp_a)
            {
                count_a++;
                a_start++;
            }
            while(b_start >= 0 && bs[b_start] == temp_b)
            {
                count_b++;
                b_start--;
            }
            ans += count_a * count_b;
        }
        else if(as[a_start]+bs[b_start]>T)
        {
            b_start--;
        }
        else
        {
            a_start++;
        }
    }
    cout << ans;




}
