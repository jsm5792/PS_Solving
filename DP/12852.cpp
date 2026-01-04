#include <iostream>

using namespace std;

int a[1000002];
int b[1000002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    a[1]=0;
    for(int i=2;i<=N;i++)
    {
        a[i] = a[i-1] + 1;
        b[i] = i-1;
        if(i%2==0 &&  a[i]>a[i/2]+1)
        {
            a[i] = a[i/2]+1;
            b[i] = i/2;
        }
        if(i%3==0 &&  a[i]>a[i/3]+1)
        {
            a[i] = a[i/3]+1;
            b[i] = i/3;
        }
    }
    cout << a[N]<< '\n';
    int index = N;
    while(1)
    {
        cout << index << ' ';
        if(index == 1)
        {
            break;
        }
        index = b[index];
    }

}
