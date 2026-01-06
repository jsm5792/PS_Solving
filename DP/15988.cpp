#include <iostream>

using namespace std;
long long a[1000005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    a[1]=1;
    a[2]=2;
    a[3]=4;
    for(int i=4;i<1000003;i++)
    {
        a[i] = a[i-1] + a[i-2] + a[i-3];
        a[i] %= 1000000009;
    }
    for(int i=0;i<T;i++)
    {
        int index;
        cin >>index;
        cout << a[index] <<'\n';
    }

}
