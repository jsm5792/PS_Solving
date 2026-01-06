#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long a[100005][3];
long long b[100005][3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k=1;
    while(1)
    {
        cin >> N;
        if(N==0)
        {
            break;
        }
        for(int i=0;i<N;i++)
        {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
        }
        b[0][1] = a[0][1];
        b[1][0] = b[0][1] + a[1][0];
        b[1][1] = b[0][1] + a[1][1];
        b[1][2] = b[0][1] + a[1][2];
        for(int i=2; i<N;i++)
        {
            b[i][0] = min(b[i-1][0],b[i-1][1])+a[i][0];
            b[i][1] = min({b[i-1][0],b[i-1][1],b[i-1][2],b[i][0]})+a[i][1];
            b[i][2] = min({b[i-1][1],b[i-1][1],b[i][1]})+a[i][2];
        }
        cout << k <<". " <<b[N-1][1] <<'\n';
        k++;
    }
}
