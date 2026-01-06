#include <iostream>
#include <algorithm>

using namespace std;

int N;
int a[10003];
int b[10003][3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
    }
    b[0][1] = a[0];
    for(int i=1;i<N;i++)
    {
        b[i][0] = max({b[i-1][0],b[i-1][1],b[i-1][2]});
        b[i][1] = b[i-1][0] + a[i];
        b[i][2] = b[i-1][1] + a[i];
    }
    cout << max({b[N-1][0],b[N-1][1],b[N-1][2]});


}
