#include <iostream>

using namespace std;

long long a[1000];
long long b[1000];
int N;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >>N;
    a[1] = 0;
    b[1] = 1;
    for(int i=2;i<=N;i++)
    {
        a[i] = a[i-1] + b[i-1];
        b[i] = a[i-1];
    }
    cout << a[N]+b[N];
}
