#include <iostream>

using namespace std;

int N, M;
long long a[41];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin >> M;
    a[0] =1;
    a[1] =1;
    a[2] =2; 
    for(int i=3;i<=N;i++)
    {
        a[i] = a[i-1]+a[i-2];
    }
    long long ans=1;
    int index=0;
    for(int j=0;j<M;j++)
    {
        int temp;
        cin >> temp;
        ans *= a[temp-index-1];
        index = temp;
    }
    ans *= a[N-index];
    cout << ans;

}
