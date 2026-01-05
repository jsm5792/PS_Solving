#include <iostream>

using namespace std;

int T, W;
int a[1003];
int b[1003][31];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T >> W;
    for(int i=1;i<=T;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<=T;i++)
    {
        for(int j=0;j<=min(i,W);j++)
        {
            if(a[i]==(j%2)+1)
            {
                if(j==0)
                {
                    b[i][j] = b[i-1][j]+1;

                }
                else
                {
                    b[i][j]=max(b[i-1][j-1],b[i-1][j])+1;
                }

            }
            else
            {
                b[i][j] = b[i-1][j];
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=W;i++)
    {
        ans = max(b[T][i],ans);
    }
    cout << ans;

    
}