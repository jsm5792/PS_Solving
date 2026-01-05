#include <iostream>

using namespace std;

int N;
int a[1003];
int b[1003];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
        b[i] = 1;
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i])
            {
                b[i] = max(b[j]+1,b[i]);
            }
        }
    }
    int ans=0;
    for(int i=0;i<N;i++)
    {
        ans = max(b[i],ans);
    }
    cout <<ans;



}
