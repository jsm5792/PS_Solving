#include <iostream>
#include <algorithm>

using namespace std;

int a[100005][2];
int b[100005][2];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin >> a[j][i];
            }
        }
        b[0][0] = a[0][0];
        b[0][1] = a[0][1];
        if(N>1)
        {
            b[1][0] = a[0][1] + a[1][0];
            b[1][1] = a[0][0] + a[1][1];
        }
        for(int i=2;i<N;i++)
        {
            b[i][0] = max({b[i-1][1],b[i-2][0],b[i-2][1]}) + a[i][0];
            b[i][1] = max({b[i-1][0],b[i-2][0],b[i-2][1]}) + a[i][1];
        }
        cout << max(b[N-1][0],b[N-1][1])<<'\n';
    }
}
