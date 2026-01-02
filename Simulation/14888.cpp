#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int a[200];

int main()
{
    cin >> N;
    int b[4];
    vector<int> v; 
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<4;i++)
    {
        cin >> b[i];
        for(int j=0;j<b[i];j++)
        {
            v.push_back(i);
        }
    }
    int max = -1e9-1;
    int min = 1e9+1;
    do
    {
        int sum = a[0];
        for(int i=0;i<N-1;i++)
        {
            if(v[i]==0)
            {
                sum += a[i+1];
            }
            else if(v[i]==1)
            {
                sum -= a[i+1];                
            }
            else if(v[i]==2)
            {
                sum *= a[i+1];
            }
            else
            {
                sum /= a[i+1];
            }
        }
        if (sum>max)
        {
            max = sum;
        }
        if(sum <min)
        {
            min = sum;
        }
    } while (next_permutation(v.begin(),v.end()));
    cout << max <<'\n' << min;
    

    
}
