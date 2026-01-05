#include <iostream>

using namespace std;
int T;
long long a[103];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    a[1] = 1;
    a[2] = 1;
    a[3] = 1;
    a[4] = 2;
    a[5] = 2;
    for(int i=6;i<=100;i++)
    {
        a[i] = a[i-1] + a[i-5];
    }    

    for(int i=0;i<T;i++)
    {
        int n;
        cin >> n;
        cout << a[n]<<'\n';
    }
}
