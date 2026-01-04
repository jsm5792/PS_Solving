#include <iostream>
#include <vector>

using namespace std;

int N,K;
int a[10005];
vector <int> coin;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for(int i=0;i<N;i++)
    {
        int b;
        cin >> b;
        coin.push_back(b);
    }
    
    a[0] = 1;
    for(int i=0;i<N;i++)
    {
        for(int j=coin[i];j<=K;j++)
        {
            if(j-coin[i]>=0)
            {
                a[j] += a[j-coin[i]];
            }
        }
    }
    cout << a[K];

    
}
