#include <iostream>

using namespace std;

int N;
int a[1000003];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    a[1]=1;
    a[2]=2;
    cin >> N;
    for(int i=3;i<=N;i++)
    {
        a[i]=a[i-1]+a[i-2];
        a[i] %= 15746;
    }
    cout << a[N];




}
