#include <iostream>

using namespace std;

int N,M;
int a[100002];
int b[100002];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    b[0]=0;
    for(int i=1;i<=N;i++)
    {
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }
    for(int i=0;i<M;i++)
    {
        int x,y;
        cin >> x >> y;
        cout << b[y]-b[x-1] << '\n';
    }
    
}
